`define  ADDR_W 5
`define  DATA_W 32
module IFU#(parameter ADDR_WIDTH =`ADDR_W, parameter DATA_WIDTH =`DATA_W)(
    input clk,
    input rst,
    input [DATA_WIDTH-1:0] pc,
    output  [DATA_WIDTH-1:0] inst
);
    import "DPI-C" function int pmem_read(input int raddr);

    assign inst = pmem_read(pc);

endmodule
