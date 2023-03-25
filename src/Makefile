
output: main.o event.o data.o
	g++ main.o event.o data.o -o output

main.o: main.cpp
	g++ -c main.cpp

event.o: event.cpp event.h
	g++ -c event.cpp

data.o: data.cpp data.h
	g++ -c data.cpp

clean: 
	rm *.o output
