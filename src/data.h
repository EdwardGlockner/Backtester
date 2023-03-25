#ifndef DATA
#define DATA

#include <iostream>

class DataHandler {
	public:
		DataHandler();
		~DataHandler();
		void get_latest_data(std::string symbol, int observation);
		void update_latest_data();


	private:
};


class HistoricCSVDataHandler : public DataHandler {
	public:
		HistoricCSVDataHandler(std::string in_event, std::string in_csv_path, std::string in_symbol_list, std::string in_source);
		~HistoricCSVDataHandler();
		std::string event;
		std::string csv_path;
		std::string symbol_list;
		std::string source;

		void open_convert_csv_file(std::string source);
		void get_new_data(std::string symbol);
		void get_latest_data(std::string symbol, std::string num_obs);
		void update_latest_data();
		void create_baseline_dataframe();
		void parse_yahoo_csv(std::string symbol);

	private:	
		std::string symbol_data;
		std::string symbol_dataframe;
		std::string latest_symbol_data;
		std::string all_data;
		std::string continue_backtest;
		std::string time_col;
		std::string price_col;

}; 


#endif

