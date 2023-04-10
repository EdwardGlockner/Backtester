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
	t_data testing_data = t_data();
	testing_data.t_open_convert_csv_file();
	testing_data.t_get_new_bar();
	testing_data.t_get_latest_bars();


	return 0;
}
