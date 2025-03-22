#include "cpu.hpp"

SC_HAS_PROCESS(Cpu);


int read_ddr_cnt=0;
int write_ddr_cnt=0;

Cpu::Cpu(sc_core::sc_module_name name): sc_module(name), offset(sc_core::SC_ZERO_TIME)
{
	
	SC_THREAD(get_ip);
	SC_REPORT_INFO("CPU","Constructed.");


}
Cpu::~Cpu()
{
	SC_REPORT_INFO("Cpu", "Destroyed.")
}


void Cpu::clean()
{
	provocation=false;
	for(int i=0; i<=80 ; i++)
		write_bram(i,' ');
}

int Cpu::get_ip()
{
	SC_REPORT_INFO("CPU", "Starting HARD processing");

	write_hard(ADDR_START,1) // Pokretanje IP-a
	bool done=false;
	while(!done)
	{
		int ready=read_hard(ADDR_READY);
		SC_REPORT_INFO("CPU", ("Ready status: " + std::to_string(ready)).c_str());

		if(ready){
			write_hard(ADDR_START,0);
			done=true;
		}else{
			wait(DELAY,SC_NS);
		}
	}	
	SC_REPORT_INFO("CPU","Geting winner value")
	int ip_result=read_hard(ADDR_WIN_VAL);
	SC_REPORT_INFO("CPU","HARD processing done")
	return ip_result;
}

int Cpu::GetValue(int column) //uzima kolonu(1-7),i ako je ta kolona u tom redu free,upisuje u nju.
{
	if(column>7)
		return 0;
	int n;
	for(int i=0; i<=6; i++)
	{	
		char temp_s
		read_bram(column+7*i,&temp_s,1)
		if(temp_s== ' ')
		{
			n=column+7*i;
			break;
		}
	}
	if (n>42)
		return 0;
	return n;
}


void Cpu::Board() // funkcija za crtanje table

{
	cout<<endl<<"    1   "<<"    2   "<<"    3   "<<"    4   "<<"    5   "<<"    6   "<<"    7   "<<endl;

    int j = 42;
    for(int i = 0 ; i<= 23 ; i++)
    {
        if(i % 4 == 0)
            cout<<string(57,'-');
        else
        {
            if( (i - 2) % 4 == 0)
            {
                j=42-(0.25*i+0.5)*6-((0.25*i+0.5)-1) ;
                for(int i = 0 ; i<=6 ; i++)
                {
                    cout<<"|"<<"   "<<input[j]<<"   ";
                    j++;
                }
                cout<<"|";
            }
            else
            {
                for(int i = 0 ; i<=6 ; i++)
                    cout<<"|"<<string(7,' ');
                cout<<"|";
            }
        }
        cout<<endl;
    }
    cout<<string(57,'-');
    if(provocation == true)
        cout<<endl<<"Hehe I'm sure of my winning :D "<<endl;
}


void Cpu::PlayPosition(char XO)
{
	static std::vector<int>moves;
	static size_t currentMoveIndex=0;

	if (moves.empty()|| currentMoveIndex>=moves.size())
	{
		moves.clear();
		int move;
		ifstream inputFile("input.txt");
		if(!inputFile.is_open())
		{
			cerr<<"Can't open file"<<endl;
			exit(1);
		}

		while (inputFile>>move)
		{
			moves.push_back(move);
		}
		inputFile.close();
		currentMoveIndex=0;
	}

	if(currentMoveIndex<move.size())
	{
		int sth=GetValue(moves[currentMoveIndex++]);
		char temp_xo;
		read_bram(sth,&temp_xo,1);
		while(sth==0 || temp_xo!='')
		{
			cout<<"WARNING: Invalid move or position already taken. Taking the next available position."<<endl;
			sth=GetValue(moves[currentMoveIndex]);
		}

		if (sth !=0)
		{
			write_bram(sth,XO);
		}
		else
		{
			cout<<"ERROR: invalid move or position already taken."<<endl;
		}

	}

}

int Cpu::AIManager()
{
	float chanse[2]={9999999 , 0 };
	for(int column=1; column<=7; column ++)
	{
		PlayOut=0;
		EVA=0;
		int PlayNumber=GetValue(column);

		if(PlayNumber!=0)
		{
			write_bram(PlayNumber,'O');
			if(get_ip()==2)
			{
				write_bram(PlayNumber,' ');
				return PlayNumber;
			}

			float temp=-(100*NegaMax(1));
			if(PlayOut !=0)
				temp -=((100*EVA)/PlayOut);
			if(-temp>=100)
				provocation=true;
			if(chanse[0]>temp)
			{
				chanse[0]=temp;
				chanse[1]=PlayNumber;
			}
			write_bram(PlayNumber,' ');
		}
	}

	return chanse[1];


}

int Cpu::NegaMax(int Depth)
{
	char XO;
	int PlayNumber[8]=0,0,0,0,0,0,0,0}; // The values of the input[] for every column
    int chance=0;
    if(Depth % 2 != 0)
        XO='X';
    else
        XO='O';
    for(int column = 1 ; column <= 7 ; column ++)
    	 PlayNumber[column]=GetValue(column);
    for(int column = 1 ; column <= 7 ; column++)
    {
        if(PlayNumber[column] != 0)
        {
        	write_bram(PlayNumber[column],XO);
        	//!!read_hard??!!

        	if(get_ip()!=0)
        	{
        		PlayOut ++;
        		if(XO=='O')
        			EVA ++;
        		else
        			EVA--;
        		write_bram(PlayNumber[column],' ');
        		return -1;
        	}
        	write_bram(PlayNumber[column],' ');

        }
    if(Depth<=6)
    {
    	for(int column=1; column<=7; column++)
    	{
    		int temp=0;
    		if(PlayNumber[column]!=0)
    		{
    			write_bram(PlayNumber[column],XO);

    			
    			if (get_ip() !=0)
    			{
    				PlayOut++;
    				if(XO=='O')
    					EVA++;
    				else
    					EVA--;
    				write_bram(PlayNumber[column],' ');
    				return -1;
    			}
    			temp=NegaMax(Depth+1);
    			if(column==1)
    				chanse=temp;
    			if(chanse<temp)
    				chanse=temp
    			write_bram(PlayNumber[column], ' ');
    		}
    	}
    }    
    return -chance;
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