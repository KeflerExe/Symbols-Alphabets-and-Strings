all: cadenas_main

cadenas_main: cadenas_main.o cadenas.o
	g++ -o cadenas_main cadenas.o cadenas_main.o -std=c++2a

cadenas.o: cadenas.cc
	g++ -c -o cadenas.o cadenas.cc -std=c++2a

cadenas_main.o: cadenas_main.cc
	g++ -c -o cadenas_main.o cadenas_main.cc -std=c++2a

clean:
	-rm cadenas_main.o cadenas.o cadenas_main