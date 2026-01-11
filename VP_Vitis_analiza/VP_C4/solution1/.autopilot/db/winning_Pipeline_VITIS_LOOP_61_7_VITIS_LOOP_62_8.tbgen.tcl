set moduleName winning_Pipeline_VITIS_LOOP_61_7_VITIS_LOOP_62_8
set isTopModule 0
set isCombinational 0
set isDatapathOnly 0
set isPipelined 0
set pipeline_type none
set FunctionProtocol ap_ctrl_hs
set isOneStateSeq 0
set ProfileFlag 0
set StallSigGenFlag 0
set isEnableWaveformDebug 1
set hasInterrupt 0
set DLRegFirstOffset 0
set DLRegItemOffset 0
set C_modelName {winning_Pipeline_VITIS_LOOP_61_7_VITIS_LOOP_62_8}
set C_modelType { int 1 }
set C_modelArgList {
	{ board int 8 regular {bram 42 { 1 3 } 1 1 }  }
	{ symbol_3_out int 8 regular {pointer 1}  }
}
set hasAXIMCache 0
set C_modelArgMapList {[ 
	{ "Name" : "board", "interface" : "bram", "bitwidth" : 8, "direction" : "READONLY"} , 
 	{ "Name" : "symbol_3_out", "interface" : "wire", "bitwidth" : 8, "direction" : "WRITEONLY"} , 
 	{ "Name" : "ap_return", "interface" : "wire", "bitwidth" : 1} ]}
# RTL Port declarations: 
set portNum 14
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ board_Addr_A sc_out sc_lv 32 signal 0 } 
	{ board_EN_A sc_out sc_logic 1 signal 0 } 
	{ board_WEN_A sc_out sc_lv 1 signal 0 } 
	{ board_Din_A sc_out sc_lv 8 signal 0 } 
	{ board_Dout_A sc_in sc_lv 8 signal 0 } 
	{ symbol_3_out sc_out sc_lv 8 signal 1 } 
	{ symbol_3_out_ap_vld sc_out sc_logic 1 outvld 1 } 
	{ ap_return sc_out sc_lv 1 signal -1 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "board_Addr_A", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "board", "role": "Addr_A" }} , 
 	{ "name": "board_EN_A", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "board", "role": "EN_A" }} , 
 	{ "name": "board_WEN_A", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "board", "role": "WEN_A" }} , 
 	{ "name": "board_Din_A", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "board", "role": "Din_A" }} , 
 	{ "name": "board_Dout_A", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "board", "role": "Dout_A" }} , 
 	{ "name": "symbol_3_out", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "symbol_3_out", "role": "default" }} , 
 	{ "name": "symbol_3_out_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "symbol_3_out", "role": "ap_vld" }} , 
 	{ "name": "ap_return", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "ap_return", "role": "default" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "",
		"CDFG" : "winning_Pipeline_VITIS_LOOP_61_7_VITIS_LOOP_62_8",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1", "real_start" : "0",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "15", "EstimateLatencyMax" : "184",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"IsBlackBox" : "0",
		"Port" : [
			{"Name" : "board", "Type" : "Bram", "Direction" : "I"},
			{"Name" : "symbol_3_out", "Type" : "Vld", "Direction" : "O"}],
		"Loop" : [
			{"Name" : "VITIS_LOOP_61_7_VITIS_LOOP_62_8", "PipelineType" : "no",
				"LoopDec" : {"FSMBitwidth" : "17", "FirstState" : "ap_ST_fsm_state2", "LastState" : ["ap_ST_fsm_state15"], "QuitState" : ["ap_ST_fsm_state15"], "PreState" : ["ap_ST_fsm_state1"], "PostState" : ["ap_ST_fsm_state16", "ap_ST_fsm_state17"], "OneDepthLoop" : "0", "OneStateBlock": ""}}]}]}


set ArgLastReadFirstWriteLatency {
	winning_Pipeline_VITIS_LOOP_61_7_VITIS_LOOP_62_8 {
		board {Type I LastRead 12 FirstWrite -1}
		symbol_3_out {Type O LastRead -1 FirstWrite 15}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "15", "Max" : "184"}
	, {"Name" : "Interval", "Min" : "15", "Max" : "184"}
]}

set PipelineEnableSignalInfo {[
]}

set Spec2ImplPortList { 
	board { bram {  { board_Addr_A MemPortADDR2 1 32 }  { board_EN_A MemPortCE2 1 1 }  { board_WEN_A MemPortWE2 1 1 }  { board_Din_A MemPortDIN2 1 8 }  { board_Dout_A MemPortDOUT2 0 8 } } }
	symbol_3_out { ap_vld {  { symbol_3_out out_data 1 8 }  { symbol_3_out_ap_vld out_vld 1 1 } } }
}
