`define  ADDR_W 5
`define  DATA_W 32
module EXU#(parameter DATA_WIDTH =`DATA_W)(
    input  clk,
    input  rst,
    input  [DATA_WIDTH-1:0] inst, 
    input  [DATA_WIDTH-1:0] src1,
    input  [DATA_WIDTH-1:0] src2,
    input  [11:0] immi,
    input  [11:0] imms,
    input  [11:0] immb,
    input  [19:0] immu,
    input  [19:0] immj,  
    input  [DATA_WIDTH-1:0] pc,
    output [DATA_WIDTH-1:0] mem_addr,
    output [DATA_WIDTH-1:0] mem_wdata,
    output                  mem_we,
    output [3:0]            mem_wmask,
    input  [DATA_WIDTH-1:0] mem_rdata,
    output                  rf_wen,
    output [4:0]            rf_waddr,
    output [DATA_WIDTH-1:0] rf_wdata,
    // branch/jump
    output                  jal,
    input  [DATA_WIDTH-1:0] a0_val,
    output                  ebreak,
    output [DATA_WIDTH-1:0] halt_code,
    output [DATA_WIDTH-1:0] jal_target
);

    ALU #( .DATA_WIDTH (`DATA_W))
    my_alu(
        .clk       (clk),
        .rst       (rst),
        .inst      (inst),
        .src1      (src1),
        .src2      (src2),
        .immi      (immi),
        .imms      (imms),
        .immu      (immu),
        .immb      (immb),
        .immj      (immj),
        .mem_addr  (mem_addr),
        .mem_wdata (mem_wdata),
        .mem_we    (mem_we),
        .mem_wmask (mem_wmask),
        .mem_rdata (mem_rdata),
        .rf_wen    (rf_wen),
        .rf_waddr  (rf_waddr),
        .rf_wdata  (rf_wdata),
        .jal       (jal),
        .a0_val    (a0_val),
        .ebreak    (ebreak),
        .halt_code (halt_code),
        .pc        (pc),
        .jal_target(jal_target)
    );

endmodule

module ALU #(parameter DATA_WIDTH =`DATA_W)(
    input  clk,
    input  rst,
    input  [DATA_WIDTH-1:0] inst, 
    input  [DATA_WIDTH-1:0] src1,
    input  [DATA_WIDTH-1:0] src2,
    input  [11:0] immi,
    input  [11:0] imms,
    input  [19:0] immu,
    input  [11:0] immb,
    input  [19:0] immj,

    input  [DATA_WIDTH-1:0] pc,
    output reg [DATA_WIDTH-1:0] mem_addr,
    output reg [DATA_WIDTH-1:0] mem_wdata,
    output reg                  mem_we,
    output reg [3:0]            mem_wmask,
    input      [DATA_WIDTH-1:0] mem_rdata,
    output reg                  rf_wen,
    output reg [4:0]            rf_waddr,
    output reg [DATA_WIDTH-1:0] rf_wdata,
    output reg                  jal,
    input      [DATA_WIDTH-1:0] a0_val,
    output reg                  ebreak,
    output reg [DATA_WIDTH-1:0] halt_code,
    output     [DATA_WIDTH-1:0] jal_target
);
    import "DPI-C" function void ebreak_notice(input int halt_code);

    parameter EBREAK  = 32'b00000000000100000000000001110011;
    //TYPE_J
    parameter JAL     = 32'b?????????????????????????1101111;
    //TYPE_I
    parameter LB      = 32'b?????????????????000?????0000011;
    parameter LH      = 32'b?????????????????001?????0000011;
    parameter LW      = 32'b?????????????????010?????0000011;
    parameter LBU     = 32'b?????????????????100?????0000011;
    parameter LHU     = 32'b?????????????????101?????0000011;
    parameter JALR    = 32'b?????????????????000?????1100111;
    parameter ADDI    = 32'b?????????????????000?????0010011;
    parameter SLTI    = 32'b?????????????????010?????0010011;
    parameter SLTIU   = 32'b?????????????????011?????0010011;
    parameter XORI    = 32'b?????????????????100?????0010011;
    parameter ORI     = 32'b?????????????????110?????0010011;
    parameter ANDI    = 32'b?????????????????111?????0010011;
    parameter SLLI    = 32'b0000000??????????001?????0010011;
    parameter SRLI    = 32'b0000000??????????101?????0010011;
    parameter SRAI    = 32'b0100000??????????101?????0010011;
    //TYPE_S
    parameter SB      = 32'b?????????????????000?????0100011;
    parameter SH      = 32'b?????????????????001?????0100011;
    parameter SW      = 32'b?????????????????010?????0100011;   
    //TUPE_U
    parameter LUI     = 32'b?????????????????????????0110111;
    parameter AUIPC   = 32'b?????????????????????????0010111;
    //TYPE_B
    parameter BEQ     = 32'b?????????????????000?????1100011;
    parameter BNE     = 32'b?????????????????001?????1100011;
    parameter BGE     = 32'b?????????????????101?????1100011;
    parameter BLT     = 32'b?????????????????100?????1100011;
    parameter BGEU    = 32'b?????????????????111?????1100011;
    parameter BLTU    = 32'b?????????????????110?????1100011;
    //TYPE_R
    parameter ADD     = 32'b0000000??????????000?????0110011;
    parameter SUB     = 32'b0100000??????????000?????0110011;
    parameter SLL     = 32'b0000000??????????001?????0110011;
    parameter SLT     = 32'b0000000??????????010?????0110011;
    parameter SLTU    = 32'b0000000??????????011?????0110011;
    parameter XOR     = 32'b0000000??????????100?????0110011;
    parameter SRL     = 32'b0000000??????????101?????0110011;
    parameter SRA     = 32'b0100000??????????101?????0110011;
    parameter OR      = 32'b0000000??????????110?????0110011;
    parameter AND     = 32'b0000000??????????111?????0110011;
    always @(posedge clk) begin
        if(rst)begin
            mem_addr  <= 0;
            mem_wdata <= 0;
            mem_we    <= 0;
            mem_wmask <= 4'b0;
            rf_wen    <= 0;
            rf_waddr  <= 0;
            rf_wdata  <= 0;
            jal       <= 0;
            ebreak    <= 0;
            halt_code <= 0;
        end
        else begin
            // default: 
            mem_we    = 0;
            mem_wmask = 4'b0;
            rf_wen    = 0;
            jal       = 0;
            ebreak    = 0;
            halt_code = 0;
            casez(inst)
                EBREAK  : begin
                    ebreak    = 1;
                    halt_code = a0_val;
                    ebreak_notice(a0_val);
                end
                BEQ   : begin
                    mem_addr = pc + {{19{immb[11]}}, immb, 1'b0};
                    jal  = (src1 == src2) ? 1 : 0;
                end
                BNE   : begin
                    mem_addr = pc + {{19{immb[11]}}, immb, 1'b0};
                    jal  = (src1 != src2) ? 1 : 0;
                end
                BGE   : begin
                    mem_addr = pc + {{19{immb[11]}}, immb, 1'b0};
                    jal  = ($signed(src1) >= $signed(src2)) ? 1 : 0;
                end
                BLT   : begin
                    mem_addr = pc + {{19{immb[11]}}, immb, 1'b0};
                    jal  = ($signed(src1) < $signed(src2)) ? 1 : 0;
                end 
                BGEU  : begin
                    mem_addr = pc + {{19{immb[11]}}, immb, 1'b0};
                    jal  = (src1 >= src2) ? 1 : 0;
                end
                BLTU  : begin
                    mem_addr = pc + {{19{immb[11]}}, immb, 1'b0};
                    jal  = (src1 < src2) ? 1 : 0;
                end
                ADD   : begin
                    mem_addr = src1 + src2;
                    rf_wen   = 1;
                    rf_waddr = inst[11:7];
                    rf_wdata = src1 + src2;
                end
                SUB   : begin
                    mem_addr = src1 + src2;
                    rf_wen   = 1;
                    rf_waddr = inst[11:7];
                    rf_wdata = src1 - src2;
                end
                SLTU  : begin
                    mem_addr = src1 + src2;
                    rf_wen   = 1;
                    rf_waddr = inst[11:7];
                    rf_wdata = (src1 < src2) ? 1 : 0;
                end
                XOR   : begin
                    mem_addr = src1 + src2;
                    rf_wen   = 1;
                    rf_waddr = inst[11:7];
                    rf_wdata = src1 ^ src2;
                end
                OR    : begin
                    mem_addr = src1 + src2;
                    rf_wen   = 1;
                    rf_waddr = inst[11:7];
                    rf_wdata = src1 | src2;
                end
                SLL   : begin
                    mem_addr = src1 + src2;
                    rf_wen   = 1;
                    rf_waddr = inst[11:7];
                    rf_wdata = src1 <<(src2 & 32'h1f);
                end
                AND   : begin
                    mem_addr = src1 + src2;
                    rf_wen   = 1;
                    rf_waddr = inst[11:7];
                    rf_wdata = src1 & src2;
                end
                SLT   : begin
                    mem_addr = src1 + src2;
                    rf_wen   = 1;
                    rf_waddr = inst[11:7];
                    rf_wdata = ($signed(src1) < $signed(src2)) ? 1 : 0;
                end
                SRL   : begin
                    mem_addr = src1 + src2;
                    rf_wen   = 1;
                    rf_waddr = inst[11:7];
                    rf_wdata = src1 >> (src2 & 32'h1f);
                end
                SRA   : begin
                    mem_addr = src1 + src2;
                    rf_wen   = 1;
                    rf_waddr = inst[11:7];
                    rf_wdata = $signed(src1) >>> (src2 & 32'h1f);
                end

                JALR  : begin
                    jal_target = (src1 + {{20{immi[11]}}, immi}) & ~1;
                    rf_wen   = 1;
                    rf_waddr = inst[11:7];
                    rf_wdata = pc + 4;
                    jal      = 1;
                end
                JAL   : begin
                    jal_target = pc + {{11{immj[19]}}, immj, 1'b0};
                    rf_wen   = 1;
                    rf_wdata = pc + 4;
                    rf_waddr = inst[11:7];
                    jal      = 1;
                end
                LB    : begin
                    mem_addr = src1 + {{20{immi[11]}}, immi};
                    rf_wen   = 1;
                    rf_waddr = inst[11:7];
                    rf_wdata = {{24{mem_rdata[7]}}, mem_rdata[7:0]};
                end
                LH    : begin
                    mem_addr = src1 + {{20{immi[11]}}, immi};
                    rf_wen   = 1;
                    rf_waddr = inst[11:7];
                    rf_wdata = {{16{mem_rdata[15]}}, mem_rdata[15:0]};
                end
                LW    : begin
                    mem_addr = src1 + {{20{immi[11]}}, immi};
                    rf_wen   = 1;
                    rf_waddr = inst[11:7];
                    rf_wdata = mem_rdata;
                end
                LBU   : begin
                    mem_addr = src1 + {{20{immi[11]}}, immi};
                    rf_wen   = 1;
                    rf_waddr = inst[11:7];
                    rf_wdata = {24'b0, mem_rdata[7:0]};
                end
                LHU   : begin
                    mem_addr = src1 + {{20{immi[11]}}, immi};
                    rf_wen   = 1;
                    rf_waddr = inst[11:7];
                    rf_wdata = {16'b0, mem_rdata[15:0]};
                end
                ADDI  : begin
                    mem_addr = src1 + {{20{immi[11]}}, immi};
                    rf_wen   = 1;
                    rf_waddr = inst[11:7];
                    rf_wdata = src1 + {{20{immi[11]}}, immi};
                end
                SW    : begin
                    mem_addr  = src1 + {{20{imms[11]}}, imms};
                    mem_wdata = src2;
                    mem_wmask = 4'b1111;
                    mem_we    = 1;
                end
                SH    : begin
                    mem_addr  = src1 + {{20{imms[11]}}, imms};
                    mem_wdata = src2;
                    mem_wmask = 4'b0011;
                    mem_we    = 1;
                end 
                SB    : begin
                    mem_addr  = src1 + {{20{imms[11]}}, imms};
                    mem_wdata = src2;
                    mem_wmask = 4'b0001;
                    mem_we    = 1;
                end
                LUI   : begin
                    mem_addr = {immu, 12'b0};
                    rf_wen   = 1;
                    rf_waddr = inst[11:7];
                    rf_wdata = {immu, 12'b0};
                end
                AUIPC : begin
                    mem_addr = {immu, 12'b0};
                    rf_wen   = 1;
                    rf_waddr = inst[11:7];
                    rf_wdata = {immu, 12'b0} + pc;
                end
                SLTI  : begin
                    mem_addr = src1 + {{20{immi[11]}}, immi};
                    rf_wen   = 1;
                    rf_waddr = inst[11:7];
                    rf_wdata = ($signed(src1) < $signed({{20{immi[11]}}, immi})) ? 1 : 0;
                end
                SLTIU : begin
                    mem_addr = src1 + {{20{immi[11]}}, immi};
                    rf_wen   = 1;
                    rf_waddr = inst[11:7];
                    rf_wdata = (src1 < {20'b0, immi}) ? 1 : 0;
                end
                XORI  : begin
                    mem_addr = src1 + {{20{immi[11]}}, immi};
                    rf_wen   = 1;
                    rf_waddr = inst[11:7];
                    rf_wdata = (src1 ^ {{20{immi[11]}}, immi});
                end
                ORI   : begin
                    mem_addr = src1 + {{20{immi[11]}}, immi};
                    rf_wen   = 1;
                    rf_waddr = inst[11:7];
                    rf_wdata = (src1 | {{20{immi[11]}}, immi});
                end
                ANDI  : begin
                    mem_addr = src1 + {{20{immi[11]}}, immi};
                    rf_wen   = 1;
                    rf_waddr = inst[11:7];
                    rf_wdata = (src1 & {{20{immi[11]}}, immi});
                end
                SRAI  : begin
                    mem_addr = src1 + {{20{immi[11]}}, immi};
                    rf_wen   = 1;
                    rf_waddr = inst[11:7];
                    rf_wdata = $signed(src1) >>> (immi & 6'b011111);
                end
                SLLI  : begin
                    mem_addr = src1 + {{20{immi[11]}}, immi};
                    rf_wen   = 1;
                    rf_waddr = inst[11:7];
                    rf_wdata = src1 << (immi & 6'b011111);
                end
                SRLI  : begin
                    mem_addr = src1 + {{20{immi[11]}}, immi};
                    rf_wen   = 1;
                    rf_waddr = inst[11:7];
                    rf_wdata = src1 >> (immi & 6'b011111);
                end
                default : begin
                    mem_addr = 0;
                    $display("UNKNOWN INST: pc=%h inst=%h", pc, inst);
                    ebreak_notice(halt_code);
                end

            endcase
        end
        
    end


endmodule