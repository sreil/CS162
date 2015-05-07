PROGS := Lab3

all: $(PROGS)

Lab3: main.cpp Dice.cpp Dice.h LoadedDice.cpp LoadedDice.h
	g++ -g main.cpp Dice.cpp Dice.h LoadedDice.cpp LoadedDice.h -o Lab3
	
clean:
	rm -f $(PROGS) *.o*~