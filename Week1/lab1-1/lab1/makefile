PROGS := lab1-1 lab1-2

all: $(PROGS)


lab1-1: lab1-1.cpp
	g++ -g lab1-1.cpp -o lab1-1
		
lab1-2: lab1-2.cpp f.cpp f.h g.cpp g.h
	g++ -g lab1-2.cpp f.cpp g.cpp g.h -o lab1-2

clean:
	rm -f $(PROGS) *.o *~