#ifndef _BRAM_HPP_
#define _BRAM_HPP_

#include<sysyemc>
#include<iostream>
#include<vector>
#include <tlm>
#include <tlm_utils/simple_target_socket.h>
#include "defines.hpp"

class Bram: public sc_core::sc_module
{
	public:
		Bram(sc_core::sc_module_name name);
		~Bram();

		tlm_utils::simple_target_socket<Bram>bram_socket_1;
		tlm_utils::simple_target_socket<Bram>bram_socket_2;

	protected:
		void b_transport(pl_t &,sc_core::sc_time &);
		std::std::vector<unsigned char> mem;

};

#endif