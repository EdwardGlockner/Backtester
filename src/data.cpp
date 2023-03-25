#include "data.h"

/* CLASS DATAHANDLER */
DataHandler::DataHandler() {

}

DataHandler::~DataHandler() {

}

/* CLASS HISTORICCSVDATAHANDLER */
HistoricCSVDataHandler::HistoricCSVDataHandler(std::string in_events, std::string in_csv_path, std::vector <std::string> in_symbol_list) {

	events= in_events;
	csv_path = in_csv_path;
	symbol_list = in_symbol_list;
	continue_backtest = true;
	
}

HistoricCSVDataHandler::~HistoricCSVDataHandler() {

}

void HistoricCSVDataHandler :: open_convert_csv_file() {
	
	for (int i = 0; i < symbol_list.size(); i++) {
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

    			if (symbol_data.find(symbol_list[i]) == symbol_data.end()) {
				std::vector<data_struct> newVec;
				newVec.push_back(current_data);
        			symbol_data[symbol_list[i]] = newVec;
    			} else {
				symbol_data[symbol_list[i]].push_back(current_data);
    			}
	
			line = "";
		}
		for (int j = 0; j < symbol_data[symbol_list[i]].size(); j++) {
			symbol_data[symbol_list[i]][j].display();
		}
	}
	
}

void HistoricCSVDataHandler :: get_new_data(std::string symbol) {

}

void HistoricCSVDataHandler :: get_latest_data(std::string symbol, std::string num_obs) {

}

void HistoricCSVDataHandler :: update_latest_data() {

}

void HistoricCSVDataHandler :: create_baseline_dataframe() {

}

void HistoricCSVDataHandler :: parse_yahoo_csv(std::string symbol) {

}

