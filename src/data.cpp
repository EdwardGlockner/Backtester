#include "data.h"

/* CLASS DATAHANDLER */
DataHandler::DataHandler() {

}

DataHandler::~DataHandler() {

}

/* CLASS HISTORICCSVDATAHANDLER */
HistoricCSVDataHandler::HistoricCSVDataHandler() {

}

HistoricCSVDataHandler::HistoricCSVDataHandler(std::string in_events, std::string in_csv_path, std::vector <std::string> in_symbol_list) {
	/*
	 *
	 */

	events= in_events;
	csv_path = in_csv_path;
	symbol_list = in_symbol_list;
	continue_backtest = true;
	
}

HistoricCSVDataHandler::~HistoricCSVDataHandler() {
	/*
	 *
	 */

}

void HistoricCSVDataHandler :: open_convert_csv_file() {
	/*
	 *
	 */
	
	for (int i = 0; i < symbol_list.size(); i++) {
		parse_yahoo_csv(symbol_list[i]);
		latest_index[symbol_list[i]] = 0;
		
		/*
		for (int j = 0; j < symbol_data[symbol_list[i]].size(); j++) {
			symbol_data[symbol_list[i]][j].display();
			}
			*/
	}
	
}

HistoricCSVDataHandler :: Bar HistoricCSVDataHandler :: get_new_bar(std::string symbol) {
	/*
	 *
	 */
	data_struct temp_struct = symbol_data[symbol][latest_index[symbol]];
	latest_index[symbol]++;
	
	struct Bar return_bar(symbol, temp_struct.Date, temp_struct.Open, temp_struct.High, temp_struct.Close, temp_struct.AdjClose, temp_struct.Volume);
	
	return return_bar;
}

HistoricCSVDataHandler :: Bar HistoricCSVDataHandler :: get_latest_bars(std::string symbol, int num_obs) {
	/*
	 *
	 */
	if (latest_symbol_data.find(symbol) == latest_symbol_data.end()) {
		return Bar("","",0,0,0,0,0);
	}
	else{
		return latest_symbol_data[symbol][-num_obs];
	}	
}

void HistoricCSVDataHandler :: update_bars(std::string symbol) {
	/*
	 *
	 */
	for (int i = 0; i < symbol_list.size(); i++) {
		if (latest_index[symbol_list[i]] > symbol_data[symbol_list[i]].size()) {
			continue_backtest = false;
		}
		else {
			struct Bar bar = get_new_bar(symbol_list[i]);
			latest_symbol_data[symbol_list[i]].push_back(bar);
		}//self.events.put(MarketEvent())

	}

}


void HistoricCSVDataHandler :: parse_yahoo_csv(std::string symbol) {
	/*
	 *
	 */
	std::fstream inputFile;
	inputFile.open("/Users/edwardglockner/OneDrive - Uppsala universitet/Big Python Projects/Backtester/Data/YahooData/data/TSLA_2023-03-25_1m");

	std::string line = "";
	std::getline(inputFile, line);
	line = "";

	while (std::getline(inputFile, line)) {
		std::string Date;
		double Open;
		double High;
		double Close;
		double AdjClose;
		int Volume;

		std::string tempString = "";

		std::stringstream inputString(line);
		
		std::getline(inputString, Date, ',');

		std::getline(inputString, tempString, ',');
		Open = std::atof(tempString.c_str());
		tempString = "";

		std::getline(inputString, tempString, ',');
		High = std::atof(tempString.c_str());
		tempString = "";

		std::getline(inputString, tempString, ',');
		Close = std::atof(tempString.c_str());
		tempString = "";

		std::getline(inputString, tempString, ',');
		AdjClose = std::atof(tempString.c_str());
		tempString = "";

		std::getline(inputString, tempString, ',');
		Volume = std::atoi(tempString.c_str());

		data_struct current_data(Date, Open, High, Close, AdjClose, Volume);

		if (symbol_data.find(symbol) == symbol_data.end()) {
			std::vector<data_struct> newVec;
			newVec.push_back(current_data);
			symbol_data[symbol] = newVec;
		} else {
			symbol_data[symbol].push_back(current_data);
		}

		line = "";
	}

	std::vector <Bar> temp;
	latest_symbol_data[symbol] = temp;
	
}

