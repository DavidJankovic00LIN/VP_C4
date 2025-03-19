#include "hard.hpp"

SC_HAS_PROCESS(Hard);

Hard::Hard(sc_module_name name);
	sc_modlue(name),
	ready(1)
	{
		interconnect_socket.register_b_transport(this,&Hard::b_reansport);
		SC_REPORT_INFO("Hard", "Constructed.")
	}

Hard::~Hard()
{
	SC_REPORT_INFO("Hard","Destroyed");
}

void Hard::b_transport(pl_t &pl,sc_time &offset)
{
	
}


//hardverska winning funkcija
uint8_t Hard::winning(sc_time &system_offset){
	pl_t pl;

	if (start == 1 && ready==1){
		ready=0;
		offset+=sc_time(DELAY,SC_NS);
	}

	else if(start==0 && ready==0)
	{
		cout<<"Processing started"<<endl;
			for(int row = 0; row < 6; row++){ // 6 redova
		        for (int col = 0; col <= 3; col++) { // Maksimalno 4 startne tačke po redu
		            char symbol = input[row * 7 + col];
		            if (symbol != ' ' &&
		                symbol == input[row * 7 + col + 1] &&
		                symbol == input[row * 7 + col + 2] &&
		                symbol == input[row * 7 + col + 3]) {
		                return (symbol == 'X') ? 1 : 2;
		            }
		        }
		    }

		    // Provera vertikalnih linija
		    for (int col = 0; col < 7; col++) { // 7 kolona
		        for (int row = 0; row <= 2; row++) { // Maksimalno 3 startne tačke po koloni
		            char symbol = input[row * 7 + col];
		            if (symbol != ' ' &&
		                symbol == input[(row + 1) * 7 + col] &&
		                symbol == input[(row + 2) * 7 + col] &&
		                symbol == input[(row + 3) * 7 + col]) {
		                return (symbol == 'X') ? 1 : 2;
		            }
		        }
		    }

		    // Provera dijagonala (desno-nadole)
		    for (int row = 0; row <= 2; row++) { // 3 startne tačke po redu
		        for (int col = 0; col <= 3; col++) { // 4 startne tačke po koloni
		            char symbol = input[row * 7 + col];
		            if (symbol != ' ' &&
		                symbol == input[(row + 1) * 7 + col + 1] &&
		                symbol == input[(row + 2) * 7 + col + 2] &&
		                symbol == input[(row + 3) * 7 + col + 3]) {
		                return (symbol == 'X') ? 1 : 2;
		            }
		        }
		    }

		    // Provera dijagonala (levo-nadole)
		    for (int row = 0; row <= 2; row++) { // 3 startne tačke po redu
		        for (int col = 3; col < 7; col++) { // 4 startne tačke po koloni
		            char symbol = input[row * 7 + col];
		            if (symbol != ' ' &&
		                symbol == input[(row + 1) * 7 + col - 1] &&
		                symbol == input[(row + 2) * 7 + col - 2] &&
		                symbol == input[(row + 3) * 7 + col - 3]) {
		                return (symbol == 'X') ? 1 : 2;
		            }
		        }
		    }

		    // Provera da li je tabla puna
		    for (int i = 0; i < 42; i++) { // 42 pozicije
		        if (input[i] == ' ') {
		            return 0; // Igra se nastavlja
		        }
		    }

		    return 3; // Nerešeno
		    //end of winning()


	ready =1;		    
	}	//stay inside
	
}

void Hard::write_bram(sc_uint<64> addr, unsigned char val)
{

}

unsigned char Hard::read_bram(sc_uint <64> addr)
{

}