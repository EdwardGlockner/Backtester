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
HistoricCSVDataHandler::HistoricCSVDataHandler(std::string in_event, std::string in_csv_path, std::string in_symbol_list, std::string in_source) {
	event = in_event;
	csv_path = in_csv_path;
	symbol_list = in_symbol_list;
	source = in_source;

	symbol_data = "";
	symbol_dataframe = "";
	latest_symbol_data = "";
	all_data = "";
	continue_backtest = "";
	time_col = "";
	price_col = "";	
}

HistoricCSVDataHandler::~HistoricCSVDataHandler() {

}

void HistoricCSVDataHandler :: open_convert_csv_file(std::string source) {

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

