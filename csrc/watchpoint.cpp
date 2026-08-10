#include "common.h"

#define NR_WP 32
word_t expr(char *e, bool *success);
typedef struct watchpoint {
  int NO;
  int data;//值
  char expr[128]; //表达式
  struct watchpoint *next;

  /* TODO: Add more members if necessary */

} WP;
//链表


static WP wp_pool[NR_WP] = {};
static WP *head = NULL, *free_ = NULL;

void init_wp_pool() {
  int i;
  for (i = 0; i < NR_WP; i ++) {
    wp_pool[i].NO = i;
    wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
  }

  head = NULL;
  free_ = wp_pool;
}

/* TODO: Implement the functionality of watchpoint */
//从free中拿出
WP* new_wp(char *expr) { 
  if (free_ == NULL) {
    assert(0); //没有空闲监视点
  }
  
  //从free头部取出一个节点
  WP *wp = free_;
  free_ = free_->next;
  
  //初始化新监视点
  wp->next = NULL;
  wp->data = 0;
  wp->expr[0] = '\0';
  
  //复制表达式到监视点
  if (expr != NULL) {
    strncpy(wp->expr, expr, sizeof(wp->expr) - 1);
    wp->expr[sizeof(wp->expr) - 1] = '\0';
  }
  
  //添加到链表头部
  wp->next = head;
  head = wp;
  
  return wp;
}
//归还到free
void free_wp(WP *wp) {
  if (wp == NULL) return;
  
  //从head链表中移除wp
  if (head == wp) {

    head = head->next;
  } else {

    WP *prev = head;
    while (prev != NULL && prev->next != wp) {
      prev = prev->next;
    }
    if (prev != NULL) {
      prev->next = wp->next;
    }
  }
  
  //将wp插入到free头部
  wp->next = free_;
  free_ = wp;
}
//打印所有间断点
void print_wp_list() {
  WP *curr = head;
  if (curr == NULL) {
    printf("No watchpoints.\n");
    return;
  }
  
  printf("Active watchpoints:\n");
  while (curr != NULL) {
    printf("  NO %d: %s data: %d\n", 
           curr->NO, curr->expr, curr->data);
    curr = curr->next;
  }
}
int check_watchpoints() {
  WP *curr = head;
  while (curr != NULL) {
    bool success;
    int new_val = expr(curr->expr, &success);
    if (!success) {
      printf("Watchpoint %d: expression evaluation failed\n", curr->NO);
      curr = curr->next;
      continue;
    }
    if (new_val != curr->data) {
      //值发生变化，更新并返回触发的监视点编号
      curr->data = new_val;
      return curr->NO;
    }
    curr = curr->next;
  }
  return -1;//没有监视点触发
}
void delete_wp(int NO) {
  WP *curr = head;
  WP *prev = NULL;
  
  while (curr != NULL) {
    if (curr->NO == NO) {
      //找到要删除的监视点
      if (prev == NULL) {
        head = curr->next;
      } else {
        prev->next = curr->next;
      }
      //归还到free
      curr->next = free_;
      free_ = curr;
      return;
    }
    prev = curr;
    curr = curr->next;
  }
}