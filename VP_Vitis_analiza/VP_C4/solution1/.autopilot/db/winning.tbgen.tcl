set moduleName winning
set isTopModule 1
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
set C_modelName {winning}
set C_modelType { void 0 }
set C_modelArgList {
	{ board int 8 regular {bram 42 { 1 3 } 1 1 }  }
	{ result int 32 regular {pointer 1}  }
}
set hasAXIMCache 0
set C_modelArgMapList {[ 
	{ "Name" : "board", "interface" : "bram", "bitwidth" : 8, "direction" : "READONLY"} , 
 	{ "Name" : "result", "interface" : "wire", "bitwidth" : 32, "direction" : "WRITEONLY"} ]}
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
	{ board_Clk_A sc_out sc_logic 1 signal 0 } 
	{ board_Rst_A sc_out sc_logic 1 signal 0 } 
	{ result sc_out sc_lv 32 signal 1 } 
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
 	{ "name": "board_Clk_A", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "board", "role": "Clk_A" }} , 
 	{ "name": "board_Rst_A", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "board", "role": "Rst_A" }} , 
 	{ "name": "result", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "result", "role": "default" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1", "2", "3", "4", "5"],
		"CDFG" : "winning",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1", "real_start" : "0",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "18", "EstimateLatencyMax" : "1169",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"IsBlackBox" : "0",
		"Port" : [
			{"Name" : "board", "Type" : "Bram", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "1", "SubInstance" : "grp_winning_Pipeline_VITIS_LOOP_13_1_VITIS_LOOP_14_2_fu_71", "Port" : "board", "Inst_start_state" : "1", "Inst_end_state" : "2"},
					{"ID" : "4", "SubInstance" : "grp_winning_Pipeline_VITIS_LOOP_61_7_VITIS_LOOP_62_8_fu_92", "Port" : "board", "Inst_start_state" : "7", "Inst_end_state" : "8"},
					{"ID" : "5", "SubInstance" : "grp_winning_Pipeline_VITIS_LOOP_77_9_fu_99", "Port" : "board", "Inst_start_state" : "9", "Inst_end_state" : "10"},
					{"ID" : "2", "SubInstance" : "grp_winning_Pipeline_VITIS_LOOP_29_3_VITIS_LOOP_30_4_fu_78", "Port" : "board", "Inst_start_state" : "3", "Inst_end_state" : "4"},
					{"ID" : "3", "SubInstance" : "grp_winning_Pipeline_VITIS_LOOP_45_5_VITIS_LOOP_46_6_fu_85", "Port" : "board", "Inst_start_state" : "5", "Inst_end_state" : "6"}]},
			{"Name" : "result", "Type" : "None", "Direction" : "O"}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_winning_Pipeline_VITIS_LOOP_13_1_VITIS_LOOP_14_2_fu_71", "Parent" : "0",
		"CDFG" : "winning_Pipeline_VITIS_LOOP_13_1_VITIS_LOOP_14_2",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1", "real_start" : "0",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "15", "EstimateLatencyMax" : "352",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"IsBlackBox" : "0",
		"Port" : [
			{"Name" : "board", "Type" : "Bram", "Direction" : "I"},
			{"Name" : "symbol_out", "Type" : "Vld", "Direction" : "O"}],
		"Loop" : [
			{"Name" : "VITIS_LOOP_13_1_VITIS_LOOP_14_2", "PipelineType" : "no",
				"LoopDec" : {"FSMBitwidth" : "17", "FirstState" : "ap_ST_fsm_state2", "LastState" : ["ap_ST_fsm_state15"], "QuitState" : ["ap_ST_fsm_state15"], "PreState" : ["ap_ST_fsm_state1"], "PostState" : ["ap_ST_fsm_state16", "ap_ST_fsm_state17"], "OneDepthLoop" : "0", "OneStateBlock": ""}}]},
	{"ID" : "2", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_winning_Pipeline_VITIS_LOOP_29_3_VITIS_LOOP_30_4_fu_78", "Parent" : "0",
		"CDFG" : "winning_Pipeline_VITIS_LOOP_29_3_VITIS_LOOP_30_4",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1", "real_start" : "0",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "15", "EstimateLatencyMax" : "310",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"IsBlackBox" : "0",
		"Port" : [
			{"Name" : "board", "Type" : "Bram", "Direction" : "I"},
			{"Name" : "symbol_1_out", "Type" : "Vld", "Direction" : "O"}],
		"Loop" : [
			{"Name" : "VITIS_LOOP_29_3_VITIS_LOOP_30_4", "PipelineType" : "no",
				"LoopDec" : {"FSMBitwidth" : "17", "FirstState" : "ap_ST_fsm_state2", "LastState" : ["ap_ST_fsm_state15"], "QuitState" : ["ap_ST_fsm_state15"], "PreState" : ["ap_ST_fsm_state1"], "PostState" : ["ap_ST_fsm_state16", "ap_ST_fsm_state17"], "OneDepthLoop" : "0", "OneStateBlock": ""}}]},
	{"ID" : "3", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_winning_Pipeline_VITIS_LOOP_45_5_VITIS_LOOP_46_6_fu_85", "Parent" : "0",
		"CDFG" : "winning_Pipeline_VITIS_LOOP_45_5_VITIS_LOOP_46_6",
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
			{"Name" : "symbol_2_out", "Type" : "Vld", "Direction" : "O"}],
		"Loop" : [
			{"Name" : "VITIS_LOOP_45_5_VITIS_LOOP_46_6", "PipelineType" : "no",
				"LoopDec" : {"FSMBitwidth" : "17", "FirstState" : "ap_ST_fsm_state2", "LastState" : ["ap_ST_fsm_state15"], "QuitState" : ["ap_ST_fsm_state15"], "PreState" : ["ap_ST_fsm_state1"], "PostState" : ["ap_ST_fsm_state16", "ap_ST_fsm_state17"], "OneDepthLoop" : "0", "OneStateBlock": ""}}]},
	{"ID" : "4", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_winning_Pipeline_VITIS_LOOP_61_7_VITIS_LOOP_62_8_fu_92", "Parent" : "0",
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
				"LoopDec" : {"FSMBitwidth" : "17", "FirstState" : "ap_ST_fsm_state2", "LastState" : ["ap_ST_fsm_state15"], "QuitState" : ["ap_ST_fsm_state15"], "PreState" : ["ap_ST_fsm_state1"], "PostState" : ["ap_ST_fsm_state16", "ap_ST_fsm_state17"], "OneDepthLoop" : "0", "OneStateBlock": ""}}]},
	{"ID" : "5", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_winning_Pipeline_VITIS_LOOP_77_9_fu_99", "Parent" : "0", "Child" : ["6"],
		"CDFG" : "winning_Pipeline_VITIS_LOOP_77_9",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1", "real_start" : "0",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "4", "EstimateLatencyMax" : "130",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"IsBlackBox" : "0",
		"Port" : [
			{"Name" : "board", "Type" : "Bram", "Direction" : "I"}],
		"Loop" : [
			{"Name" : "VITIS_LOOP_77_9", "PipelineType" : "UPC",
				"LoopDec" : {"FSMBitwidth" : "3", "FirstState" : "ap_ST_fsm_state1", "FirstStateIter" : "", "FirstStateBlock" : "ap_ST_fsm_state1_blk", "LastState" : "ap_ST_fsm_state3", "LastStateIter" : "", "LastStateBlock" : "ap_ST_fsm_state3_blk", "QuitState" : "ap_ST_fsm_state3", "QuitStateIter" : "", "QuitStateBlock" : "ap_ST_fsm_state3_blk", "OneDepthLoop" : "1", "has_ap_ctrl" : "1", "has_continue" : "0"}}]},
	{"ID" : "6", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_winning_Pipeline_VITIS_LOOP_77_9_fu_99.flow_control_loop_pipe_sequential_init_U", "Parent" : "5"}]}


set ArgLastReadFirstWriteLatency {
	winning {
		board {Type I LastRead 12 FirstWrite -1}
		result {Type O LastRead -1 FirstWrite 2}}
	winning_Pipeline_VITIS_LOOP_13_1_VITIS_LOOP_14_2 {
		board {Type I LastRead 12 FirstWrite -1}
		symbol_out {Type O LastRead -1 FirstWrite 15}}
	winning_Pipeline_VITIS_LOOP_29_3_VITIS_LOOP_30_4 {
		board {Type I LastRead 12 FirstWrite -1}
		symbol_1_out {Type O LastRead -1 FirstWrite 15}}
	winning_Pipeline_VITIS_LOOP_45_5_VITIS_LOOP_46_6 {
		board {Type I LastRead 12 FirstWrite -1}
		symbol_2_out {Type O LastRead -1 FirstWrite 15}}
	winning_Pipeline_VITIS_LOOP_61_7_VITIS_LOOP_62_8 {
		board {Type I LastRead 12 FirstWrite -1}
		symbol_3_out {Type O LastRead -1 FirstWrite 15}}
	winning_Pipeline_VITIS_LOOP_77_9 {
		board {Type I LastRead 0 FirstWrite -1}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "18", "Max" : "1169"}
	, {"Name" : "Interval", "Min" : "19", "Max" : "1170"}
]}

set PipelineEnableSignalInfo {[
]}

set Spec2ImplPortList { 
	board { bram {  { board_Addr_A MemPortADDR2 1 32 }  { board_EN_A MemPortCE2 1 1 }  { board_WEN_A MemPortWE2 1 1 }  { board_Din_A MemPortDIN2 1 8 }  { board_Dout_A MemPortDOUT2 0 8 }  { board_Clk_A mem_clk 1 1 }  { board_Rst_A mem_rst 1 1 } } }
	result { ap_none {  { result out_data 1 32 } } }
}

set maxi_interface_dict [dict create]

# RTL port scheduling information:
set fifoSchedulingInfoList { 
}

# RTL bus port read request latency information:
set busReadReqLatencyList { 
}

# RTL bus port write response latency information:
set busWriteResLatencyList { 
}

# RTL array port load latency information:
set memoryLoadLatencyList { 
}
