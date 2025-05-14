OPTIONS = -O2 -Wall -std=c++11   # pour optimiser  -Wextra

all: clean tp3

tp3: tp3.o
	g++ ${OPTIONS} -o tp3 tp3.o

tp3.o: tp3.cpp
	g++ ${OPTIONS} -c tp3.cpp

clean:
	rm -f *.o tp3


