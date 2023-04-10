/*

*/

#include "t_data.h"
#include "../src/Event/event.h"
#include <queue>

t_data :: t_data() {
	std::queue<Event> events;
	MarketEvent t_event = MarketEvent();
	events.push(t_event);
	std::string csv_path = "/Users/edwardglockner/OneDrive - Uppsala universitet/Big Python Projects/Backtester/tests/resources/test.csv";
	std::vector <std::string> symbol_list;
	symbol_list.push_back("TSLA");
	num_test = 1;
	
	testing = HistoricCSVDataHandler(events, csv_path, symbol_list);
	

}


t_data :: ~t_data() {


}


void t_data :: t_open_convert_csv_file() {

	if (testing.latest_index["TSLA"] == 0) {
		std::cout << "HistoricCSVDataHandler, test " << num_test << ": \t function {open_convert_csv_file} passed test!" << std::endl;
		++num_test;
	}
	else {
		std::cout << "HistoricCSVDataHandler, test " << num_test << ": \t function {open_convert_csv_file} not passed test!" << std::endl;
	}

	HistoricCSVDataHandler::data_struct line1 = HistoricCSVDataHandler::data_struct("2023-03-16 09:30:00-04:00",180.3650054931641,181.25,180.3000030517578,180.7700042724609,180.7700042724609,3207535);
	HistoricCSVDataHandler::data_struct line2 = HistoricCSVDataHandler::data_struct("2023-03-16 09:31:00-04:00",180.72000122070312,181.3498992919922,179.8800048828125,179.9600067138672,179.9600067138672,778782);

	
	if (testing.symbol_data["TSLA"][0].Close == line1.Close &&
		testing.symbol_data["TSLA"][0].Open == line1.Open &&
		testing.symbol_data["TSLA"][0].High == line1.High &&
		testing.symbol_data["TSLA"][0].Close == line1.Close &&
		testing.symbol_data["TSLA"][0].AdjClose == line1.AdjClose &&
		testing.symbol_data["TSLA"][0].Volume == line1.Volume) {
		
		if (testing.symbol_data["TSLA"][1].Close == line2.Close &&
			testing.symbol_data["TSLA"][1].Open == line2.Open &&
			testing.symbol_data["TSLA"][1].High == line2.High &&
			testing.symbol_data["TSLA"][1].Close == line2.Close &&
			testing.symbol_data["TSLA"][1].AdjClose == line2.AdjClose &&
			testing.symbol_data["TSLA"][1].Volume == line2.Volume) {

			std::cout << "HistoricCSVDataHandler, test " << num_test << ": \t function {open_convert_csv_file} passed test!" << std::endl;
			++num_test;

		}
		else {
			std::cout << "HistoricCSVDataHandler, test " << num_test << ": \t function {open_convert_csv_file} not passed test!" << std::endl;
		}

	}	
	else {
		std::cout << "HistoricCSVDataHandler, test " << num_test << ": \t function {open_convert_csv_file} not passed test!" << std::endl;
	}
	testing.update_bars("TSLA");
}


void t_data :: t_get_new_bar() {
	testing.latest_index["TSLA"] = 0;	
	int old_index = testing.latest_index["TSLA"];
	HistoricCSVDataHandler::Bar new_bar = testing.get_new_bar("TSLA");
	int new_index = testing.latest_index["TSLA"];

	if ((new_index - old_index) == 1) {
		std::cout << "HistoricCSVDataHandler, test " << num_test << ": \t function {get_new_bar} passed test!" << std::endl;
		++num_test;
	}
	else {
		std::cout << "HistoricCSVDataHandler, test " << num_test << ": \t function {get_new_bar} not passed test!" << std::endl;
	}

	if (testing.symbol_data["TSLA"][0].Close == new_bar.Close &&
		testing.symbol_data["TSLA"][0].Open == new_bar.Open &&
		testing.symbol_data["TSLA"][0].High == new_bar.High &&
		testing.symbol_data["TSLA"][0].Close == new_bar.Close &&
		testing.symbol_data["TSLA"][0].AdjClose == new_bar.AdjClose &&
		testing.symbol_data["TSLA"][0].Volume == new_bar.Volume) {

		std::cout << "HistoricCSVDataHandler, test " << num_test << ": \t function {get_new_bar} passed test!" << std::endl;
		++num_test;

	}
	else {
		std::cout << "HistoricCSVDataHandler, test " << num_test << ": \t function {get_new_bar} not passed test!" << std::endl;
	}
	HistoricCSVDataHandler::Bar new_bar2 = testing.get_new_bar("TSLA");
	if (testing.symbol_data["TSLA"][1].Close == new_bar2.Close &&
		testing.symbol_data["TSLA"][1].Open == new_bar2.Open &&
		testing.symbol_data["TSLA"][1].High == new_bar2.High &&
		testing.symbol_data["TSLA"][1].Close == new_bar2.Close &&
		testing.symbol_data["TSLA"][1].AdjClose == new_bar2.AdjClose &&
		testing.symbol_data["TSLA"][1].Volume == new_bar2.Volume) {

		std::cout << "HistoricCSVDataHandler, test " << num_test << ": \t function {get_new_bar} passed test!" << std::endl;
		++num_test;

	}
	else {
		std::cout << "HistoricCSVDataHandler, test " << num_test << ": \t function {get_new_bar} not passed test!" << std::endl;
	}

}


void t_data :: t_get_latest_bars(){
	testing.latest_index["TSLA"] = 0;
	HistoricCSVDataHandler::Bar new_bar = testing.get_latest_bars("TSLA", 1);
	if (testing.symbol_data["TSLA"][0].Close == new_bar.Close &&
		testing.symbol_data["TSLA"][0].Open == new_bar.Open &&
		testing.symbol_data["TSLA"][0].High == new_bar.High &&
		testing.symbol_data["TSLA"][0].Close == new_bar.Close &&
		testing.symbol_data["TSLA"][0].AdjClose == new_bar.AdjClose &&
		testing.symbol_data["TSLA"][0].Volume == new_bar.Volume) {

		std::cout << "HistoricCSVDataHandler, test " << num_test << ": \t function {get_latest_bars} passed test!" << std::endl;
		++num_test;

	}
	else {
		std::cout << "HistoricCSVDataHandler, test " << num_test << ": \t function {get_latest_bars} not passed test!" << std::endl;
	}

	testing.latest_index["TSLA"] = 1;
	HistoricCSVDataHandler::Bar new_bar2 = testing.get_latest_bars("TSLA", 2);
	if (testing.symbol_data["TSLA"][0].Close == new_bar.Close &&
		testing.symbol_data["TSLA"][0].Open == new_bar.Open &&
		testing.symbol_data["TSLA"][0].High == new_bar.High &&
		testing.symbol_data["TSLA"][0].Close == new_bar.Close &&
		testing.symbol_data["TSLA"][0].AdjClose == new_bar.AdjClose &&
		testing.symbol_data["TSLA"][0].Volume == new_bar.Volume) {

		std::cout << "HistoricCSVDataHandler, test " << num_test << ": \t function {get_latest_bars} passed test!" << std::endl;
		++num_test;

	}
	else {
		std::cout << "HistoricCSVDataHandler, test " << num_test << ": \t function {get_latest_bars} not passed test!" << std::endl;
	}



}


void t_data :: t_update_bars() {

}


void t_data :: t_testing_members() {


}

