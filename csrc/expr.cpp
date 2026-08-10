/***************************************************************************************
* Copyright (c) 2014-2024 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include "common.h"

/* We use the POSIX regex functions to process regular expressions.
 * Type 'man regex' for more information about POSIX regex functions.
 */
#include <regex.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
extern "C" int pmem_read(int raddr);
extern "C" int read_reg(int idx);
extern "C" int read_pc();
struct { const char *name; int idx; } reg_map[] = {
    {"$0", 0}, {"ra", 1}, {"sp", 2}, {"gp", 3},
    {"tp", 4}, {"t0", 5}, {"t1", 6}, {"t2", 7},
    {"s0", 8}, {"s1", 9}, {"a0", 10}, {"a1", 11},
    {"a2", 12}, {"a3", 13}, {"a4", 14}, {"a5", 15},
    {"a6", 16}, {"a7", 17}, {"s2", 18}, {"s3", 19},
    {"s4", 20}, {"s5", 21}, {"s6", 22}, {"s7", 23},
    {"s8", 24}, {"s9", 25}, {"s10", 26}, {"s11", 27},
    {"t3", 28}, {"t4", 29}, {"t5", 30}, {"t6", 31},
};

typedef uint32_t word_t;
static int find_op(int p, int q);
static bool check_parentheses(int p, int q);
static word_t eval(int p,int q);
enum {
  TK_NOTYPE = 256,
  TK_EQ,// ==
  TK_NUM,// 十进制整数
  TK_HEX,// 十六进制整数
  TK_REG,// 寄存器引用
  TK_ADD,// +
  TK_SUB,// -
  TK_MUL,// *
  TK_DIV,// /
  TK_LPAREN,// (
  TK_RPAREN, // )
  TK_NOTEQ,//!=
  TK_AND, //&&
  TK_DEREF, // *
  TK_NEG,  //一元负号

  // TODO: Add more token types */

};

static word_t isa_reg_str2val(const char *s, bool *success) {
    for (int i = 0; i < 32; i++) {
      if (strcmp(s, reg_map[i].name) == 0) {
        *success = true;
        return read_reg(i);
      }
      if(s[0] == '$' && strcmp(s+1, reg_map[i].name) == 0){
        *success = true;
        return read_reg(i);
      }
    }
    if(strcmp(s,"pc") == 0 || (s[0]=='$' && strcmp(s+1,"pc")==0)){
      *success = true;
      return read_pc();
    }
  
    *success = false;
    return 0;
}

static word_t get_reg_value(const char *reg_name) {
  bool success = true;
  word_t val = isa_reg_str2val(reg_name, &success);
  if (!success) {
    printf("Invalid register name: %s\n", reg_name);
    return 0;
  }
  return val;
}

static struct rule {
  const char *regex;
  int token_type;
} rules[] = {

  /* TODO: Add more rules.
   * Pay attention to the precedence level of different rules.
   */

  {" +", TK_NOTYPE},
  {"&&", TK_AND},
  {"==", TK_EQ},
  {"!=", TK_NOTEQ},
  {"\\+", TK_ADD},
  {"-", TK_SUB},
  {"\\*", TK_MUL},
  {"/", TK_DIV},
  {"\\(", TK_LPAREN},
  {"\\)", TK_RPAREN},
  {"0x[0-9a-fA-F]+", TK_HEX},
  {"\\$[a-zA-Z_][a-zA-Z0-9_]*", TK_REG},
  {"[0-9]+", TK_NUM},

};

#define NR_REGEX ARRLEN(rules)

static regex_t re[NR_REGEX] = {};

/* Rules are used many times.
 * Therefore compile them only once before usage.
 */
void init_regex() {
  int i;
  char error_msg[128];
  int ret;

  for (i = 0; i < NR_REGEX; i ++) {
    ret = regcomp(&re[i], rules[i].regex, REG_EXTENDED);
    if (ret != 0) {
      regerror(ret, &re[i], error_msg, 128);
      panic("regex compilation failed: %s\n%s", error_msg, rules[i].regex);
    }
  }
}

typedef struct token {
  int type;
  char str[32];
} Token;

static Token tokens[32] __attribute__((used)) = {};
static int nr_token __attribute__((used))  = 0;

static bool make_token(char *e) {
  int position = 0;
  int i;
  regmatch_t pmatch;

  nr_token = 0;

  while (e[position] != '\0') {
    /* Try all rules one by one. */
    for (i = 0; i < NR_REGEX; i ++) {
      if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 && pmatch.rm_so == 0) {
        char *substr_start = e + position;
        int substr_len = pmatch.rm_eo;

        Log("match rules[%d] = \"%s\" at position %d with len %d: %.*s",
            i, rules[i].regex, position, substr_len, substr_len, substr_start);

        position += substr_len;

        switch (rules[i].token_type) {

          case TK_NOTYPE:
          break; 
          case TK_NUM:
          case TK_HEX:
          case TK_REG:
          case TK_EQ:
          case TK_NOTEQ:
          case TK_AND:
          tokens[nr_token].type = rules[i].token_type;
          strncpy(tokens[nr_token].str, substr_start, substr_len);
          tokens[nr_token].str[substr_len] = '\0';
          nr_token++;
          break;
          case TK_ADD:
          case TK_SUB:
          case TK_MUL:
          case TK_DIV:
          case TK_LPAREN:
          case TK_RPAREN:
          tokens[nr_token].type = rules[i].token_type;
          strncpy(tokens[nr_token].str, substr_start, substr_len);
          tokens[nr_token].str[substr_len] = '\0';
          nr_token++;
          break;
          default:
            assert(0);

        }
        break;
      }

        
    }
  

    if (i == NR_REGEX) {
      printf("no match at position %d\n%s\n%*.s^\n", position, e, position, "");
      return false;
    }
  }

  return true;
}


word_t expr(char *e, bool *success) {
  if (!make_token(e)) {
    *success = false;
    printf("表达式错误\n");
    return 1;
  }

  /* TODO: Insert codes to evaluate the expression. */
  for (int i = 0; i < nr_token; i ++) {
    if (tokens[i].type == TK_MUL && (i == 0 || (tokens[i - 1].type == TK_ADD||
            tokens[i - 1].type == TK_SUB||tokens[i - 1].type == TK_MUL||
            tokens[i - 1].type == TK_DIV ||tokens[i - 1].type == TK_EQ || 
            tokens[i - 1].type == TK_NOTEQ ||tokens[i - 1].type == TK_AND || tokens[i - 1].type == TK_LPAREN)) ) {
      tokens[i].type = TK_DEREF;
    }
  }

//一元负号
  for (int i = 0; i < nr_token; i++) {
    if (tokens[i].type == TK_SUB) {
      if (i == 0 ||tokens[i-1].type == TK_LPAREN ||tokens[i-1].type == TK_ADD ||
          tokens[i-1].type == TK_SUB ||tokens[i-1].type == TK_MUL ||tokens[i-1].type == TK_DIV ||
          tokens[i-1].type == TK_EQ ||tokens[i-1].type == TK_NOTEQ ||
          tokens[i-1].type == TK_AND) {
        tokens[i].type = TK_NEG;
      }
    }
  }

  *success = true;
  return (word_t)(int32_t)eval(0, nr_token - 1);
}

static word_t eval(int p,int q) {
  if (tokens[p].type == TK_NEG) {
    word_t v = eval(p + 1, q);
    return (word_t)(-(int32_t)v);
  }
   if (tokens[p].type == TK_DEREF) {

    vaddr_t addr = (vaddr_t)eval(p + 1, q);

    return pmem_read(addr);
  }
  if (p > q) {
    return 0;
  }
  else if (p == q) {
    switch (tokens[p].type) {
      case TK_NUM: return atoi(tokens[p].str);
      case TK_HEX: return strtol(tokens[p].str, NULL, 16);
      case TK_REG: return get_reg_value(tokens[p].str);
      default: return 0;
    }
  }
  else if (check_parentheses(p, q) == true) {
    return eval(p + 1, q - 1);
  }
  else {
    if (tokens[p].type == TK_DEREF) { 
      word_t addr = eval(p + 1, q);
      return *(uint32_t *)(uintptr_t)addr;
    }
    
    int op = find_op(p,q);
    word_t val1 = eval(p, op - 1);
    word_t val2 = eval(op + 1, q);

    switch (tokens[op].type) {
    case TK_ADD: return val1 + val2;
    case TK_SUB: return val1 - val2;
    case TK_MUL: return val1 * val2;
    case TK_DIV: 
      if (val2 == 0) {
        printf("表达式错误\n");
        return 0;
      }
      return val1 / val2;
    case TK_EQ:  return val1 == val2;
    case TK_NOTEQ: return val1 != val2;
    case TK_AND: return val1 && val2;
    default: assert(0);
    }
  }
}

static bool check_parentheses(int p, int q) {
  if (tokens[p].type != TK_LPAREN || tokens[q].type != TK_RPAREN) return false;

  int cnt = 0;
  for (int i = p; i <= q; i++) 
  {
    if (tokens[i].type == TK_LPAREN) cnt++;
    else if (tokens[i].type == TK_RPAREN) cnt--;
    if (cnt == 0 && i != q) 
    return false;
  }
  return cnt == 0;
}

static int find_op(int p, int q){
  int op = -1;
  int level = 0;
//优先级
  for (int i = p; i <= q; i++) {
    int t = tokens[i].type;
    if (t == TK_LPAREN) level++;
    else if (t == TK_RPAREN) level--;
    else if (level == 0 && t == TK_AND) op = i;
  }
  if (op != -1) return op;
  level = 0;
//运算符
  for (int i = p; i <= q; i++) { 
    int t = tokens[i].type;
    if (t == TK_LPAREN) level++;
    else if (t == TK_RPAREN) level--;
    else if (level == 0 && (t == TK_EQ || t == TK_NOTEQ)) op = i;
  }
  if (op != -1) return op;
  level = 0;
//计算
  for (int i = p; i <= q; i++) {
    int t = tokens[i].type;
    if (t == TK_LPAREN) level++;
    else if (t == TK_RPAREN) level--;
    else if (level == 0 && (t == TK_ADD || t == TK_SUB)) op = i;
  }
  if (op != -1) return op;
  level = 0;
  for (int i = p; i <= q; i++) {
    int t = tokens[i].type;
    if (t == TK_LPAREN) level++;
    else if (t == TK_RPAREN) level--;
    else if (level == 0 && (t == TK_MUL || t == TK_DIV)) op = i;
  }
  return op;
}