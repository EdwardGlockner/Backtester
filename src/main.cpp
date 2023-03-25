#include <iostream>
#include "event.h"
#include "data.h"

int main() {
	// Testing event.h
	OrderEvent Order("GOOG", "FX", 6, "UP");
	Order.print_order();

	// Testing data.h
	std::vector <std::string> symbol_list;
	symbol_list.push_back("test");
	HistoricCSVDataHandler data_test("test", "test", symbol_list);
	data_test.open_convert_csv_file();

	return 0;
}
