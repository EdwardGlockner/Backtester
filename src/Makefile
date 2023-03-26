
output: main.o event.o data.o
	c++ -std=c++17 main.o event.o data.o -o output

main.o: main.cpp
	c++ -std=c++17 -c main.cpp

event.o: event.cpp event.h
	c++ -std=c++17 -c event.cpp

data.o: data.cpp data.h
	c++ -std=c++17 -c data.cpp

clean: 
	rm *.o output
