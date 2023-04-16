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
	std::cout << "\nTesting the HistoricCSVDataHandler class" << std::endl;
	t_data testing_data = t_data();
	testing_data.t_open_convert_csv_file();
	testing_data.t_get_new_bar();
	testing_data.t_get_latest_bars();
	testing_data.t_update_bars();
	std::cout << "\n";

	// TESTING PERFORMANCE CLASS
	std::cout << "Testing the Performance class" << std::endl; 
	t_performance testing_performance = t_performance();
	testing_performance.t_create_sharpe_ratio();
	testing_performance.t_create_drawdowns();
	testing_performance.t_create_volatility();
	testing_performance.t_create_stddev();
	testing_performance.t_create_variance();
	testing_performance.t_create_cum_returns();
	testing_performance.t_HTML_display_report();
	testing_performance.t_test_members();
	std::cout << "\n" << std::endl;

	return 0;
}
