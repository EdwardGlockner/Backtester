
output: main.o event.o data.o strategy_base.o BAH_strategy.o execution.o
	c++ -std=c++17 main.o event.o data.o strategy_base.o BAH_strategy.o execution.o -o output

main.o: main.cpp
	c++ -std=c++17 -c main.cpp

event.o: event.cpp event.h
	c++ -std=c++17 -c event.cpp

data.o: data.cpp data.h
	c++ -std=c++17 -c data.cpp

strategy_base.o: strategy_base.cpp strategy_base.h
	c++ -std=c++17 -c strategy_base.cpp

BAH_strategy.o: BAH_strategy.cpp BAH_strategy.h
	c++ -std=c++17 -c BAH_strategy.cpp

execution.o: execution.cpp execution.h
	c++ -std=c++17 -c execution.cpp

clean: 
	rm *.o output
