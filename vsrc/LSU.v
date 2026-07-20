`define  ADDR_W 5
`define  DATA_W 32
module LSU#(parameter DATA_WIDTH =`DATA_W)(
    input  clk,
    input  we,                        
    input  [DATA_WIDTH-1:0] addr,
    input  [DATA_WIDTH-1:0] wdata,
    output reg [DATA_WIDTH-1:0] rdata
);
    import "DPI-C" function int pmem_read(input int raddr);
    import "DPI-C" function void pmem_write(input int waddr, input int wdata, input byte wmask);

    always @(*) begin
        rdata = pmem_read(addr);
    end
    always @(posedge clk) begin
        if (we) begin
            pmem_write(addr, wdata, 8'h0f);
        end
    end
endmodule
