#include <iostream>
#include "event.h"
#include "data.h"
#include "strategy_base.h"
#include "BAH_strategy.h"
#include "execution.h"
#include "performance.h"
#include "portfolio.h"

#include <unistd.h>

int main() {
	// Testing event.h
	OrderEvent Order("GOOG", "FX", 6, "UP");
	Order.print_order();

	// Testing data.h
	std::vector <std::string> symbol_list;
	symbol_list.push_back("test");
	HistoricCSVDataHandler data_test("test", "test", symbol_list);
	data_test.open_convert_csv_file();
	HistoricCSVDataHandler::Bar temp = data_test.get_new_bar("test");
	data_test.update_bars("test");
	
	// Testing strategy_base.h
	Strategy_Base strat;

	// Testing BuyAndHold_Strategy
	//BuyAndHold_Strategy BAH("test", "Test");
	//BAH.calculate_initial_bought();
	
	// Testing performance
	/*
	std::vector<float> in_returns;
	in_returns.push_back(1.0f);	
	in_returns.push_back(2.0f);
	in_returns.push_back(3.0f);
    	in_returns.push_back(4.0f);
	in_returns.push_back(5.0f);
	Performance perf(in_returns);
	std::cout<<perf.create_sharpe_ratio()<<std::endl;
	std::cout<<perf.create_volatility()<<std::endl;
	std::cout<<perf.create_variance()<<std::endl;
	std::cout<<perf.create_stddev()<<std::endl;
	*/
	return 0;
}
