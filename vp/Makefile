CC="g++"

# Project name
PROJECT = c4_specifikacija

# Source files
SRC = main.cpp interconnect.cpp hard.cpp cpu.cpp bram.cpp vp.cpp utils.cpp


$(PROJECT) : $(SRC)
	$(CC) -g -lsystemc $(SRC) -o $(PROJECT) 

run:
	./$(PROJECT)

clean:
	rm -f $(PROJECT) *.o *.vcd

.PHONY all clean run