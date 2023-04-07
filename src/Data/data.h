/*

*/
#ifndef DATA
#define DATA

#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <cmath>
#include <queue>
#include <map>
#include <string>
#include <sstream>

#include "../Event/event.h"

class DataHandler {
	/*
	 
	 */
	public:
		DataHandler();
		~DataHandler();
};


class HistoricCSVDataHandler : public DataHandler {
	/*
	 
	 */
	public:
				
		// Structure of the data for parsing Yahoo Finance data
		struct data_struct {
		public:
			data_struct() {} // default constructor
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
				std::cout << "Date: " << Date << std::endl;
			
			}

			std::string Date; //convert to datetime
			double Open;
			double High;
			double Close;
			double AdjClose;
			int Volume;

		};

		// Bar structure
		struct Bar {
		public:
			Bar() {} // default constructor
			Bar(
				std::string symbol,
				std::string datetime,
				double open,
				double high,
				double close,
				double adjclose,
				int volume		
			) {
			    Symbol = symbol;
			    DateTime = datetime; // convert to datetime object
			    Open = open;
			    High = high;
			    Close = close;
			    AdjClose = adjclose;
			    Volume = volume;
			}
			void display() {
				std::cout << "Date: " << DateTime << std::endl;
			}
			std::string Symbol;
			std::string DateTime;
			double Open;
			double High;
			double Close;
			double AdjClose;
			int Volume;
		};
		// Constructors and destructors
		HistoricCSVDataHandler();
		HistoricCSVDataHandler(std::queue<Event> in_events, std::string in_csv_path, std::vector <std::string> in_symbol_list);
		~HistoricCSVDataHandler();

		// Methods	
		void open_convert_csv_file();
		Bar get_new_bar(std::string symbol);
		Bar get_latest_bars(std::string symbol, int num_obs);
		void update_bars(std::string symbol); 
		
		// Members
		std::queue<Event> events;
		std::string csv_path;
		std::vector <std::string> symbol_list;		
		bool continue_backtest;
		std::map <std::string, std::vector <data_struct> > symbol_data;
		std::map <std::string, std::vector <Bar> > latest_symbol_data;		
		std::map <std::string, int> latest_index;

	private:
		// Methods
		void parse_yahoo_csv(std::string symbol);


}; 
#endif

