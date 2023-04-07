
output: event.o data.o strategy_base.o BAH_strategy.o execution.o performance.o portfolio.o running.o
	c++ -std=c++17 event.o data.o strategy_base.o BAH_strategy.o execution.o performance.o portfolio.o running.o -o output

event.o: ./Event/event.cpp ./Event/event.h
	c++ -std=c++17 -c ./Event/event.cpp

data.o: ./Data/data.cpp ./Data/data.h
	c++ -std=c++17 -c ./Data/data.cpp

strategy_base.o: ./Strategies/strategy_base.cpp ./Strategies/strategy_base.h
	c++ -std=c++17 -c ./Strategies/strategy_base.cpp

BAH_strategy.o: ./Strategies/BAH_strategy.cpp ./Strategies/BAH_strategy.h
	c++ -std=c++17 -c ./Strategies/BAH_strategy.cpp

execution.o: ./Execution/execution.cpp ./Execution/execution.h
	c++ -std=c++17 -c ./Execution/execution.cpp

performance.o: ./Performance/performance.cpp ./Performance/performance.h
	c++ -std=c++17 -c ./Performance/performance.cpp

portfolio.o: ./Portfolio/portfolio.cpp ./Portfolio/portfolio.h
	c++ -std=c++17 -c ./Portfolio/portfolio.cpp

running.o: running.cpp
	c++ -std=c++17 -c running.cpp

clean: 
	rm *.o output
