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
	
	HistoricCSVDataHandler testing = HistoricCSVDataHandler(events, csv_path, symbol_list);
}


t_data :: ~t_data() {


}


void t_data :: t_open_convert_csv_file() {
	testing.open_convert_csv_file();	

	if (testing.latest_index["TSLA"] == 0) {
		std::cout << "HistoricCSVDataHandler: \t function {open_convert_csv_file} passed test!" << std::endl;
	}
	else {
		std::cout << "HistoricCSVDataHandler: \t function {open_convert_csv_file} not passed test!" << std::endl;
	}

	HistoricCSVDataHandler::data_struct line1 = HistoricCSVDataHandler::data_struct("2023-03-23 09:30:00-04:00", 259.45001220703125, 259.45001220703125, 259.45001220703125, 259.45001220703125, 23406);
	HistoricCSVDataHandler::data_struct line2 = HistoricCSVDataHandler::data_struct("2023-03-23 09:31:00-04:00", 260.32000732421875, 260.9599914550781, 260.9599914550781, 260.9599914550781, 872);
	std::cout<<testing.symbol_data["TSLA"].size()<<std::endl;
	for (int i = 0; i < testing.symbol_data["TSLA"].size(); i++) {
		std::cout<<i<<std::endl;
		testing.symbol_data["TSLA"][i].display();
	}
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

			std::cout << "HistoricCSVDataHandler: \t function {open_convert_csv_file} passed test!" << std::endl;


		}
		else {
			std::cout << "HistoricCSVDataHandler: \t function {open_convert_csv_file} not passed test!" << std::endl;
		}


		
	}	
	else {
		std::cout << "HistoricCSVDataHandler: \t function {open_convert_csv_file} not passed test!" << std::endl;
	}
}


void get_new_bar() {

}


void get_latest_bars(std::string symbol, int num_obs){

}


void update_bars(std::string symbol) {

}


void testing_members() {


}

