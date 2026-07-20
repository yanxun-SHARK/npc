`define  ADDR_W 5
`define  DATA_W 32
module top#(parameter ADDR_WIDTH =`ADDR_W, parameter DATA_WIDTH =`DATA_W)(
    input  clk,
    input  rst,
    output ebreak/*verilator public*/,
    output [DATA_WIDTH-1:0] pc/*verilator public*/,
    output [DATA_WIDTH-1:0] halt_code/*verilator public*/
);
initial begin
  $dumpfile("wave.vcd");
  $dumpvars(0, top);

end
//  wire                  ebreak/*verilator public*/;
  wire                  mem_we;
  wire                  rf_wen;
  wire                  jal;
  wire [4:0]            rs1;
  wire [4:0]            rs2;
  wire [4:0]            rd;
  wire [4:0]            rf_waddr;
  wire [11:0]           immi;
  wire [11:0]           imms;
  wire [11:0]           immb;
  wire [19:0]           immu;
  wire [19:0]           immj;
  wire [DATA_WIDTH-1:0] pc_/*verilator public*/;
  wire [DATA_WIDTH-1:0] inst;
  wire [DATA_WIDTH-1:0] src1;
  wire [DATA_WIDTH-1:0] src2;
  wire [DATA_WIDTH-1:0] mem_addr; 
  wire [DATA_WIDTH-1:0] mem_wdata; 
  wire [DATA_WIDTH-1:0] mem_rdata;
  wire [DATA_WIDTH-1:0] rf_wdata;
  wire [DATA_WIDTH-1:0] a0_val;
//  wire [DATA_WIDTH-1:0] halt_code/*verilator public*/;
 
  assign pc = pc_;

   IFU# (.ADDR_WIDTH(`ADDR_W), .DATA_WIDTH (`DATA_W))
   my_IFU(
     .clk (clk),
     .rst (rst),
    .pc  (pc_),
    .inst(inst)

  );


  IDU# (.DATA_WIDTH (`DATA_W))
  my_IDU(
    .inst(inst),
    .rs1 (rs1),
    .rs2 (rs2),
    .rd  (rd),
    .immi(immi),
    .imms(imms),
    .immb(immb),
    .immu(immu),
    .immj(immj)

  );


  EXU# (.DATA_WIDTH (`DATA_W))
  my_EXU(
    .clk      (clk),
    .rst      (rst),
    .inst     (inst),
    .src1     (src1),
    .src2     (src2),
    .immi     (immi),
    .imms     (imms),
    .immb     (immb),
    .immu     (immu),
    .immj     (immj),
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



  LSU# (.DATA_WIDTH (`DATA_W))
  my_LSU(
    .clk  (clk),
    .we   (mem_we),
    .addr (mem_addr),
    .wdata(mem_wdata),
    .rdata(mem_rdata)
  );


  WBU# (.DATA_WIDTH (`DATA_W))
  my_MBU(
    .clk    (clk),
    .rst    (rst),
    .wen    (rf_wen),
    .jal    (jal),
    .addr   (mem_addr),
    .waddr  (rf_waddr),
    .wdata  (rf_wdata),
    .raddr_1(rs1),
    .raddr_2(rs2),
    .rdata_1(src1),
    .rdata_2(src2),
    .pc_out (pc_),
    .a0_val (a0_val)

  );
endmodule
