`define  ADDR_W 5
`define  DATA_W 32
module IDU #(parameter DATA_WIDTH =`DATA_W)(
    input  [DATA_WIDTH-1:0] inst,
    //common
    output [4:0]  rs1,
    output [4:0]  rs2,
    output [4:0]  rd,
    //TYPE_R
    //TYPE_I
    output [11:0] immi,
    //TYPE_S
    output [11:0] imms,
    //TYPE_B
    output [11:0] immb,
    //TYPE_U
    output [19:0] immu,
    //TYPE_J
    output [19:0] immj

);

    decode#(
        .DATA_WIDTH (`DATA_W)
    )my_decode(
        .inst(inst),
        .rs1(rs1),
        .rs2(rs2),
        .rd(rd),
        .immu(immu),
        .imms(imms),
        .immj(immj),
        .immi(immi),
        .immb(immb)
    );
   

endmodule

module decode#( parameter DATA_WIDTH =`DATA_W)(
    input  [DATA_WIDTH-1:0] inst,
    //common
    output [4:0]  rs1,
    output [4:0]  rs2,
    output [4:0]  rd,
    //TYPE_I
    output [11:0] immi,
    //TYPE_S
    output [11:0] imms,
    //TYPE_B
    output [11:0] immb,
    //TYPE_U
    output [19:0] immu,
    //TYPE_J
    output [19:0] immj
);
    assign rs1  = {inst[19:15]};
    assign rs2  = {inst[24:20]};
    assign rd   = {inst[11:7]};
    assign immi = {inst[31:20]};
    assign imms = {inst[31:25],inst[11:7]};
    assign immb = {inst[31],inst[7],inst[30:25],inst[11:8]};
    assign immu = {inst[31:12]};
    assign immj = {inst[31:31],inst[19:12],inst[20:20],inst[30:21]};

endmodule
