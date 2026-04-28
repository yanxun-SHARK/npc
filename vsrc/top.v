module top(
        input clk,
        input rst
);
initial begin
  $dumpfile("wave.vcd");
  $dumpvars(0, our);

end
reg [7:0] a;
        always @(posedge clk) begin
                if(rst) begin
                        a <= 8'b0;
                end
                else begin
                        a <= a + 1;
                end

                if(a == 8'b11111111) begin
                        $display("a = %d", a);
                        $finish();
                end
        end
endmodule



