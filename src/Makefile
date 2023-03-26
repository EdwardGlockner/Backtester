
output: main.o event.o data.o strategy_base.o BuyAndHold_Strategy.o
	c++ -std=c++17 main.o event.o data.o -o output

main.o: main.cpp
	c++ -std=c++17 -c main.cpp

event.o: event.cpp event.h
	c++ -std=c++17 -c event.cpp

data.o: data.cpp data.h
	c++ -std=c++17 -c data.cpp

strategy_base.o: strategy_base.cpp strategy_base.cpp
	c++ -std=c++17 -c strategy_base.cpp

BuyAndHold_Strategy.o: BuyAndHold_Strategy.cpp
	c++ -std=c++17 -c BuyAndHold_Strategy.cpp

clean: 
	rm *.o output
