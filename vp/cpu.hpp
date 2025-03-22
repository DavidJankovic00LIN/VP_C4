#ifndef CPU_H
#define CPU_H
#define SC_INCLUDE_FX

#include <iostream>
#include <fstream>
#include <systemc>
#include <tlm_utils/simple_initiator_socket.h>
#include <tlm_utils/simple_target_socket.h>
#include <vector>
#include <sstream>//?

#include<csrdlib>
#include<conio.h>
#include<ctime>
#include<stdin.h>



#include "hard.hpp"

using namespace std;

class Cpu:public sc_core::sc_module
{
public:
	SC_HAS_PROCESS(Cpu);
	Cpu(sc_core::sc_module_name name, char** sstrings.int argv);
	~Cpu();
	tlm_utils::simple_initiator_socket<Cpu> interconnect_socket;

protected:

	sc_core:: sc_time offset;

	void Board;
	int GetValue(int t);
	int AIManager();
	int NegaMax(int Depth);
	void Clean();
	int game_play();

	int get_ip();



	void read_bram(sc_uint<64> addr, unsigned char *all_data,int length);
	void write_bram(sc_uint<64> addr,unsigned char val);
	int read_hard(sc_uint<64> addr);
	void write_hard(sc_uint<64> addr,int val);
}

#endif