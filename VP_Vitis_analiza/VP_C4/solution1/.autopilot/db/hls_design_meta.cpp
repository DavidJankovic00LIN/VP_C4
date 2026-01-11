#include "hls_design_meta.h"
const Port_Property HLS_Design_Meta::port_props[]={
	Port_Property("ap_clk", 1, hls_in, -1, "", "", 1),
	Port_Property("ap_rst", 1, hls_in, -1, "", "", 1),
	Port_Property("ap_start", 1, hls_in, -1, "", "", 1),
	Port_Property("ap_done", 1, hls_out, -1, "", "", 1),
	Port_Property("ap_idle", 1, hls_out, -1, "", "", 1),
	Port_Property("ap_ready", 1, hls_out, -1, "", "", 1),
	Port_Property("board_Addr_A", 32, hls_out, 0, "bram", "MemPortADDR2", 1),
	Port_Property("board_EN_A", 1, hls_out, 0, "bram", "MemPortCE2", 1),
	Port_Property("board_WEN_A", 1, hls_out, 0, "bram", "MemPortWE2", 1),
	Port_Property("board_Din_A", 8, hls_out, 0, "bram", "MemPortDIN2", 1),
	Port_Property("board_Dout_A", 8, hls_in, 0, "bram", "MemPortDOUT2", 1),
	Port_Property("board_Clk_A", 1, hls_out, 0, "bram", "mem_clk", 1),
	Port_Property("board_Rst_A", 1, hls_out, 0, "bram", "mem_rst", 1),
	Port_Property("result", 32, hls_out, 1, "ap_none", "out_data", 1),
};
const char* HLS_Design_Meta::dut_name = "winning";
