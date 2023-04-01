#include <iostream>
#include "event.h"
#include "data.h"
#include "strategy_base.h"
#include "BuyAndHold_Strategy.h"

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
	

	// Testing BuyAndHold_Strategy

	return 0;
}
