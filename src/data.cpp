#include "data.h"

/* CLASS DATAHANDLER */
DataHandler::DataHandler() {

}

DataHandler::~DataHandler() {

}

void DataHandler::get_latest_data(std::string symbol, int observation) {

}

void DataHandler :: update_latest_data() {

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



	/*
	std::fstream inputFile;
	inputFile.open(csv_path);

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

		symbol_data.push_back(current_data);
	
		line = "";
	} 
	*/
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

