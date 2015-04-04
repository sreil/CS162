PROGS := lab1-1 lab1-2

all: $(PROGS)


lab1-1: lab1-1.cpp
	g++ -g lab1-1.cpp -o lab1-1
	
lab1-2: lab1-2.o g.o f.o
	g++ -g lab1-2.o g.o f.o -o lab1-2
	
lab1-2.o: lab1-2.cpp
	g++ -c lab1-2.cpp
	
g.o: g.cpp g.h
	g++ -c g.cpp
	
h.o: f.cpp f.h
	g++ -c f.cpp

clean:
	rm -f $(PROGS) *.o *~