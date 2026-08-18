module CSR(
    input  rst,
    input  clk,
    input  [11:0]CSR_waddr,
    input  [11:0]CSR_raddr,
    input  [31:0]CSR_wdata,
    output reg [31:0]CSR_rdata,
    input  ecall,
    input  [31:0]pc,
    output [31:0]mtvec_out,
    output [31:0]mepc_out
);
parameter MCYCLE     = 12'h800;
parameter MCYCLEH    = 12'h880;
parameter MVENDORID  = 12'hF11;
parameter MARCHID    = 12'hF12;
parameter MSTATUS    = 12'h300;
parameter MEPC       = 12'h341;
parameter MCAUSE     = 12'h342;
parameter MTVEC      = 12'h305;

reg [31:0]MCYCLE_reg; 
reg [31:0]MCYCLEH_reg; 
reg [31:0]MVENDORID_reg = 32'h79737978; 
reg [31:0]MARCHID_reg   = 32'h018DA58F; 
reg [31:0]MSTATUS_reg;
reg [31:0]MEPC_reg;
reg [31:0]MCAUSE_reg;
reg [31:0]MTVEC_reg;


assign mtvec_out = MTVEC_reg;
assign mepc_out  = MEPC_reg;

always @(posedge clk) begin
    if(rst) begin
        MCYCLE_reg    <=0;
        MCYCLEH_reg   <=0;
        MSTATUS_reg   <=32'h1800;
        MEPC_reg      <=0;
        MCAUSE_reg    <=0;
        MTVEC_reg     <=0;
    end
    else begin
        MCYCLE_reg <= MCYCLE_reg + 1;
        if(MCYCLE_reg[31] == 1'b1)begin
            MCYCLEH_reg <= MCYCLEH_reg + 1;
        end
        case (CSR_waddr)
            MSTATUS : MSTATUS_reg <= CSR_wdata;
            MEPC    : MEPC_reg    <= CSR_wdata;
            MCAUSE  : MCAUSE_reg  <= CSR_wdata;
            MTVEC   : MTVEC_reg   <= CSR_wdata;
            default : ;
        endcase
        if (ecall) begin
            MEPC_reg   <= pc;
            MCAUSE_reg <= 32'hB;
        end
    end
end


//read
always @(*) begin
    case (CSR_raddr)
        MCYCLE    : CSR_rdata = MCYCLE_reg;
        MCYCLEH   : CSR_rdata = MCYCLEH_reg;
        MVENDORID : CSR_rdata = MVENDORID_reg;
        MARCHID   : CSR_rdata = MARCHID_reg;
        MSTATUS   : CSR_rdata = MSTATUS_reg;
        MEPC      : CSR_rdata = MEPC_reg;
        MCAUSE    : CSR_rdata = MCAUSE_reg;
        MTVEC     : CSR_rdata = MTVEC_reg;
        default   : CSR_rdata = 32'h0;
    endcase
end

endmodule