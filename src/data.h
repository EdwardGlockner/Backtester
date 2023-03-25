#ifndef DATA
#define DATA

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>
#include <iterator>
#include <float.h>
#include <cmath>
#include <numeric>
#include <time.h>
#include <math.h>

class DataHandler {
	public:
		DataHandler();
		~DataHandler();
};


class HistoricCSVDataHandler : public DataHandler {
	public:
		HistoricCSVDataHandler(std::string in_events, std::string in_csv_path, std::vector <std::string> in_symbol_list);
		~HistoricCSVDataHandler();
		std::string events;
		std::string csv_path;
		std::vector <std::string> symbol_list;	

		
		/* Create a structure of our data, read from Yahoo Finance */
		
		struct data_struct {
		public:
			data_struct(
				std::string date,
				double open,
				double high,
				double close,
				double adjclose,
				int volume
			) {
				Date = date;
				Open = open;
				High = high;
				Close = close;
				AdjClose = adjclose;
				Volume = volume;
			}
			
			// Function to write out all the data
			void display() {
				std::cout << "Close: " << Close << std::endl;
			
			}

			std::string Date;
			double Open;
			double High;
			double Close;
			double AdjClose;
			int Volume;
		};
		std::map <std::string, std::vector <data_struct> > symbol_data;
		std::map <std::string, std::vector <data_struct> > latest_symbol_data;		    
		bool continue_backtest;

		void open_convert_csv_file();
		void get_new_data(std::string symbol);
		void get_latest_data(std::string symbol, std::string num_obs);
		void update_latest_data();
		void create_baseline_dataframe();
		void parse_yahoo_csv(std::string symbol);

}; 


#endif

