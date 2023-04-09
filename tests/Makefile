
t_output: t_event.o t_data.o t_strategy_base.o t_BAH_strategy.o t_execution.o t_performance.o t_portfolio.o t_main.o
	c++ -std=c++17 t_event.o t_data.o t_strategy_base.o t_BAH_strategy.o t_execution.o t_performance.o t_portfolio.o t_main.o -o t_output

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

clean: 
	rm *.o t_output
