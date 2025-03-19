#include "cpu.hpp"

SC_HAS_PROCESS(Cpu);

char** data_string;
int argc;
int read_ddr_cnt=0;
int write_ddr_cnt=0;

Cpu::Cpu(sc_core::sc_module_name name,char** strings, int argv): sc_module(name), offset(sc_core::SC_ZERO_TIME)
{
	if(argv>1)
	{
		i
	}
}



// funkcije za komunikaciju za bram i hardom


void Cpu::write_bram(sc_uint<64> addr, unsigned char val)
{
	pl_t pl;
	offset +=sc_core::sc_time(DELAY, sc_core::SC_NS);
	unsigned char buf;
	read_ddr_cnt++;
	buf = val;
	pl.set_address(VP_ADDR_BRAM_L + addr);
	pl.set_data_ptr(&buf);
	pl.set_command(tlm::TLM_WRITE_COMMAND);
	pl.set_response_status(tlm::TLM_INCOMPLETE_RESPONSE);
	interconnect_socket->b_transport(pl,offset);
}

void Cpu::read_bram(sc_uint<64> addr,unsigned char *all_data, int length)
{
	offset +=sc_core::sc_time((9+1) * DELAY,sc_core::SC_NS); // istraziti zasot je ovako izracunat offset?
	pl_t pl;
	unsigned char buf;
	int n=0;

	for(int i =0; i<length; i++)
	{
		write_ddr_cnt +=4;
		pl.set_address(VP_ADDR_BRAM_L +addr+i);
		pl.set_data_length(1);
		pl.set_data_ptr(&buf);
		pl.set_command(tlm::TLM_READ_COMMAND);
		pl.set_response_status(tlm::TLM_INCOMPLETE_RESPONSE);
		interconnect_socket->b_transport(pl,offset);

		all_data[n]=buf;
		n++;
	}

}
 
// proveri da li treba uint8_t mesto int kao tip funkcije, kao i neohodnu sisrinu buffera?
int Cpu::read_hard(sc_uint<64> addr)
{
	pl_t pl;
	unsigned char buf[8];
	pl.set_address(VP_ADDR_IP_HARD_L + addr);
	pl.set_data_length(1);
	pl.set_data_ptr(buf);
	pl.set_set_command(tlm::TLM_READ_COMMAND);
	pl.set_response_status(tlm::TLM_INCOMPLETE_RESPONSE);
	sc_core::sc_time offset=sc_core::SC_ZERO_TIME;
	interconnect_socket->b_transport(pl,offset);
	return toInt(buf);
}

//proceri da li je neophodna ova funkcija!
void Cpu::write_hard(sc_uint<64> addr,int val)
{
	pl_t pl;
	unsigned char buf[4];
	toUchar(buf,val); 	
    pl.set_address(VP_ADDR_IP_HARD_L + addr);
    pl.set_data_length(1);
    pl.set_data_ptr(buf);
    pl.set_command(tlm::TLM_WRITE_COMMAND);
    pl.set_response_status(tlm::TLM_INCOMPLETE_RESPONSE);
    interconnect_socket->b_transport(pl,offset);


}