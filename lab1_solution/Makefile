#Option -O3 pour le code optimisé
OPTIONS = -O3 -Wall

lab1: lab1.o point.o
	g++ $(OPTIONS) -o lab1 lab1.o point.o

lab1.o: lab1.cpp
	g++ $(OPTIONS) -c -o lab1.o lab1.cpp

point.o: point.cpp
	g++ $(OPTIONS) -c -o point.o point.cpp

clean :
	rm -f *.o
	rm -f lab1
