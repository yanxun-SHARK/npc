`define  ADDR_W 5
`define  DATA_W 32
module WBU #(parameter ADDR_WIDTH =`ADDR_W, parameter DATA_WIDTH =`DATA_W) (
    input  clk,
    input  wen,
    input  rst,
    input  jal,
    input  [DATA_WIDTH-1:0] addr,
    input  [ADDR_WIDTH-1:0] waddr,
    input  [DATA_WIDTH-1:0] wdata,
    input  [ADDR_WIDTH-1:0] raddr_1,
    input  [ADDR_WIDTH-1:0] raddr_2,
    output [DATA_WIDTH-1:0] rdata_1,
    output [DATA_WIDTH-1:0] rdata_2,
    output [DATA_WIDTH-1:0] pc_out,
    output [DATA_WIDTH-1:0] a0_val

);
    RegisterFile# (
        .ADDR_WIDTH(`ADDR_W),
        .DATA_WIDTH(`DATA_W)
    ) my_reg(
        .rst    (rst),
        .clk    (clk),
        .wen    (wen),
        .wdata  (wdata),
        .waddr  (waddr),
        .raddr_1(raddr_1),
        .raddr_2(raddr_2),
        .rdata_1(rdata_1),
        .rdata_2(rdata_2),
        .a0_val (a0_val)
    );
    
    PC_reg# (
        .DATA_WIDTH(`DATA_W)
    )my_pc(
        .rst    (rst),
        .clk    (clk),
        .jal    (jal),
        .addr   (addr),
        .pc_out (pc_out)
    ); 

        
endmodule

module RegisterFile #(parameter ADDR_WIDTH =`ADDR_W, parameter DATA_WIDTH =`DATA_W) (
    input  clk,
    input  rst,
    input  wen,  
    input  [DATA_WIDTH-1:0] wdata,
    input  [ADDR_WIDTH-1:0] waddr,
    input  [ADDR_WIDTH-1:0] raddr_1,
    input  [ADDR_WIDTH-1:0] raddr_2,
    output [DATA_WIDTH-1:0] rdata_1,
    output [DATA_WIDTH-1:0] rdata_2,
    output [DATA_WIDTH-1:0] a0_val

);

    reg [DATA_WIDTH-1:0] rf [2**ADDR_WIDTH-1:0];
    integer i;
    always @(posedge clk) begin
        if (rst) begin
            for (i = 0; i < 2**ADDR_WIDTH; i = i + 1)
                rf[i] <= 0;
        end
        else if (wen && waddr != 0) begin
            rf[waddr] <= wdata;
        end
    end
    assign rdata_1 = (raddr_1 == 0) ? 0 : rf[raddr_1];
    assign rdata_2 = (raddr_2 == 0) ? 0 : rf[raddr_2];
    assign a0_val = rf[10];
    

endmodule

module PC_reg #(parameter DATA_WIDTH =`DATA_W) (
    input  clk,
    input  jal,
    input  rst,
    input  [DATA_WIDTH-1:0] addr,
    output [DATA_WIDTH-1:0] pc_out
);
    reg [DATA_WIDTH-1:0] pc,pc_4;

    always @(posedge clk) begin
        if (rst) begin
            pc   <= 32'h80000000;
            pc_4 <= 32'h80000004;
        end
        else begin
            if (jal) begin
                pc   <= (addr & 32'hfffffffe);
                pc_4 <= (addr & 32'hfffffffe) + 4;
            end
            else begin
                pc   <= pc_4;
                pc_4 <= pc_4 + 4;
            end
        end
    end
    assign pc_out = pc;
endmodule
