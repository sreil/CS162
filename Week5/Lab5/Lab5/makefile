PROGS := Lab5

all: $(PROGS)

Lab5: main.cpp doFilter.cpp doFilter.h copy.cpp copy.h upper.cpp upper.h encrypt.cpp encrypt.h
	g++ -g main.cpp doFilter.cpp doFilter.h copy.cpp copy.h upper.cpp upper.h encrypt.cpp encrypt.h -o Lab5
	
clean:
	rm -f $(PROGS) *.o*~