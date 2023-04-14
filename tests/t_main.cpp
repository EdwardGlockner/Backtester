/*

*/

#include <iostream>

#include "t_BAH_strategy.h"
#include "t_broker.h"
#include "t_data.h"
#include "t_event.h"
#include "t_execution.h"
#include "t_performance.h"
#include "t_portfolio.h"
#include "t_strategy_base.h"


int main() {
	// TESTING DATA CLASS
	std::cout << "Testing the HistoricCSVDataHandler class" << std::endl;
	t_data testing_data = t_data();
	testing_data.t_open_convert_csv_file();
	testing_data.t_get_new_bar();
	testing_data.t_get_latest_bars();
	testing_data.t_update_bars();
	std::cout << "\n" << std::endl;

	// TESTING PERFORMANCE CLASS
	std::cout << "Testing the Performance class" << std::endl; 
	t_performance testing_performance = t_performance();

	std::cout << "\n" << std::endl;

	return 0;
}
