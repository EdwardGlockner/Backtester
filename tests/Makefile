
t_output: t_event.o t_data.o t_strategy_base.o t_BAH_strategy.o t_execution.o t_performance.o t_portfolio.o event.o data.o strategy_base.o BAH_strategy.o execution.o performance.o portfolio.o t_main.o
	c++ -std=c++17 t_event.o t_data.o t_strategy_base.o t_BAH_strategy.o t_execution.o t_performance.o t_portfolio.o event.o data.o strategy_base.o BAH_strategy.o execution.o performance.o portfolio.o t_main.o -o t_output

t_event.o:t_event.cpp t_event.h
	c++ -std=c++17 -c t_event.cpp

t_data.o: t_data.cpp t_data.h
	c++ -std=c++17 -c t_data.cpp

t_strategy_base.o: t_strategy_base.cpp t_strategy_base.h
	c++ -std=c++17 -c t_strategy_base.cpp

t_BAH_strategy.o: t_BAH_strategy.cpp t_BAH_strategy.h
	c++ -std=c++17 -c t_BAH_strategy.cpp

t_execution.o: t_execution.cpp t_execution.h
	c++ -std=c++17 -c t_execution.cpp

t_performance.o: t_performance.cpp t_performance.h
	c++ -std=c++17 -c t_performance.cpp

t_portfolio.o: t_portfolio.cpp t_portfolio.h
	c++ -std=c++17 -c t_portfolio.cpp

t_main.o: t_main.cpp
	c++ -std=c++17 -c t_main.cpp

event.o: ../src/Event/event.cpp ../src/Event/event.h
	c++ -std=c++17 -c ../src/Event/event.cpp

data.o: ../src/Data/data.cpp ../src/Data/data.h
	c++ -std=c++17 -c ../src/Data/data.cpp

strategy_base.o: ../src/Strategies/strategy_base.cpp ../src/Strategies/strategy_base.h
	c++ -std=c++17 -c ../src/Strategies/strategy_base.cpp

BAH_strategy.o: ../src/Strategies/BAH_strategy.cpp ../src/Strategies/BAH_strategy.h
	c++ -std=c++17 -c ../src/Strategies/BAH_strategy.cpp

execution.o: ../src/Execution/execution.cpp ../src/Execution/execution.h
	c++ -std=c++17 -c ../src/Execution/execution.cpp

performance.o: ../src/Performance/performance.cpp ../src/Performance/performance.h
	c++ -std=c++17 -c ../src/Performance/performance.cpp

portfolio.o: ../src/Portfolio/portfolio.cpp ../src/Portfolio/portfolio.h
	c++ -std=c++17 -c ../src/Portfolio/portfolio.cpp

clean: 
	rm *.o t_output
