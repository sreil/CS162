PROGS := Assgn3

all: $(PROGS)

Assgn3: main.cpp Dice.cpp Dice.h Fight.cpp Fight.h type.cpp type.h 
	g++ -g main.cpp Dice.cpp Fight.cpp type.cpp  -o Assgn3
	
clean:
	rm -f $(PROGS) *.o*~