`define  ADDR_W 5
`define  DATA_W 32
module IFU#(parameter ADDR_WIDTH =`ADDR_W, parameter DATA_WIDTH =`DATA_W)(
    input clk,
    input rst,
    input [DATA_WIDTH-1:0] pc,
    output reg [DATA_WIDTH-1:0] inst
);
    import "DPI-C" function int pmem_read(input int raddr);

    always @(posedge clk) begin
        if (rst)
            inst <= 32'h00000013;
        else
            inst <= pmem_read(pc);
    end
endmodule
