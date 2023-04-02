
output: main.o event.o data.o strategy_base.o BAH_strategy.o
	c++ -std=c++17 main.o event.o data.o strategy_base.o BAH_strategy.o -o output

main.o: main.cpp
	c++ -std=c++17 -c main.cpp

event.o: event.cpp event.h
	c++ -std=c++17 -c event.cpp

data.o: data.cpp data.h
	c++ -std=c++17 -c data.cpp

strategy_base.o: strategy_base.cpp strategy_base.cpp
	c++ -std=c++17 -c strategy_base.cpp

BAH_strategy.o: BAH_strategy.cpp
	c++ -std=c++17 -c BAH_strategy.cpp

clean: 
	rm *.o output
