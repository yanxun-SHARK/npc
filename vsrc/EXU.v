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
    input  [DATA_WIDTH-1:0] mem_rdata,
    output                  rf_wen,
    output [4:0]            rf_waddr,
    output [DATA_WIDTH-1:0] rf_wdata,
    // branch/jump
    output                  jal,
    input  [DATA_WIDTH-1:0] a0_val,
    output                  ebreak,
    output [DATA_WIDTH-1:0] halt_code
);

    ALU #( .DATA_WIDTH (`DATA_W))
    my_alu(
        .clk      (clk),
        .rst      (rst),
        .inst     (inst),
        .src1     (src1),
        .src2     (src2),
        .immi     (immi),
        .imms     (imms),
        .immu     (immu),
        .mem_addr (mem_addr),
        .mem_wdata(mem_wdata),
        .mem_we   (mem_we),
        .mem_rdata(mem_rdata),
        .rf_wen   (rf_wen),
        .rf_waddr (rf_waddr),
        .rf_wdata (rf_wdata),
        .jal      (jal),
        .a0_val   (a0_val),
        .ebreak   (ebreak),
        .halt_code(halt_code),
        .pc       (pc)
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
    input  [DATA_WIDTH-1:0] pc,
    output reg [DATA_WIDTH-1:0] mem_addr,
    output reg [DATA_WIDTH-1:0] mem_wdata,
    output reg                  mem_we,
    input  [DATA_WIDTH-1:0] mem_rdata,
    output reg                  rf_wen,
    output reg [4:0]            rf_waddr,
    output reg [DATA_WIDTH-1:0] rf_wdata,
    output reg                  jal,
    input  [DATA_WIDTH-1:0] a0_val,
    output reg                  ebreak,
    output reg [DATA_WIDTH-1:0] halt_code
);
    import "DPI-C" function void ebreak_notice(input int halt_code);

    parameter EBREAK  = 32'b00000000000100000000000001110011;
    parameter ADD     = 32'b0000000??????????000?????0110011;
    parameter JALR    = 32'b?????????????????000?????1100111;
    parameter LW      = 32'b?????????????????010?????0000011;
    parameter LBU     = 32'b?????????????????100?????0000011;
    parameter ADDI    = 32'b?????????????????000?????0010011;
    parameter SW      = 32'b?????????????????010?????0100011;
    parameter SB      = 32'b?????????????????000?????0100011;
    parameter LUI     = 32'b?????????????????????????0110111;
    
    always @(posedge clk) begin
        if(rst)begin
            mem_addr  <= 0;
            mem_wdata <= 0;
            mem_we    <= 0;
            rf_wen    <= 0;
            rf_waddr  <= 0;
            rf_wdata  <= 0;
            jal       <= 0;
            ebreak    <= 0;
            halt_code <= 0;
        end
        else begin
            // default
            mem_we    <= 0;
            rf_wen    <= 0;
            jal       <= 0;
            ebreak    <= 0;
            halt_code <= 0;
            casez(inst)
                EBREAK : begin
                    ebreak    <= 1;
                    halt_code <= a0_val;
                    ebreak_notice(halt_code);
                end
                ADD : begin
                    mem_addr <= src1 + src2;
                    rf_wen   <= 1;
                    rf_waddr <= inst[11:7];
                    rf_wdata <= src1 + src2;
                end
                JALR: begin
                    mem_addr <= (src1 + {{20{immi[11]}}, immi}) & ~1;
                    rf_wen   <= 1;
                    rf_waddr <= inst[11:7];
                    rf_wdata <= pc + 4;
                    jal      <= 1;
                end
                LW  : begin
                    mem_addr <= src1 + {{20{immi[11]}}, immi};
                    rf_wen   <= 1;
                    rf_waddr <= inst[11:7];
                    rf_wdata <= mem_rdata;
                end
                LBU : begin
                    mem_addr <= src1 + {{20{immi[11]}}, immi};
                    rf_wen   <= 1;
                    rf_waddr <= inst[11:7];
                    rf_wdata <= {24'b0, mem_rdata[7:0]};
                end
                ADDI: begin
                    mem_addr <= src1 + {{20{immi[11]}}, immi};
                    rf_wen   <= 1;
                    rf_waddr <= inst[11:7];
                    rf_wdata <= src1 + {{20{immi[11]}}, immi};
                end
                SW  : begin
                    mem_addr  <= src1 + {{20{imms[11]}}, imms};
                    mem_wdata <= src2;
                    mem_we    <= 1;
                end
                SB  : begin
                    mem_addr  <= src1 + {{20{imms[11]}}, imms};
                    mem_wdata <= src2;
                    mem_we    <= 1;
                end
                LUI : begin
                    mem_addr <= {immu, 12'b0};
                    rf_wen   <= 1;
                    rf_waddr <= inst[11:7];
                    rf_wdata <= {immu, 12'b0};
                end
                default : begin
                    mem_addr <= 0;
                    $display("UNKNOWN INST: pc=%h inst=%h", pc, inst);
                    ebreak_notice(halt_code);
                end
            endcase
        end
        
    end


endmodule
