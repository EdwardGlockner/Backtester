#ifndef PORTFOLIO
#define PORTFOLIO

#include "event.h"
class Portfolio {
	public:
		Portfolio();
		~Portfolio();
		void update_signal(Event event);
		void update_fill(Event event);

	private:

};

class NaivePortfolio : public Portfolio{
	public:
		NaivePortfolio(std::string in_bars, std::string in_events, std::string in_start_date, float in_initial_capital = 1000000);
		~NaivePortfolio();

		void construct_all_positions();
		void construct_all_holdings();
		void construct_current_holdings();
		void update_time_index();
		void update_positions_from_fill();
		void update_holdings_from_fill();
		void update_fill();
		void generate_naive_order();
		void update_signal();
		void create_equity_curve_dataframe();
		
		std::string bars;
	       	std::string events;
		std::string start_date;	
		std::string symbol_list;
		std::string all_positions;
		std::string current_positions;
		std::string all_holdings;
		std::string current_holdings;
		float initial_capital;

	
	private:


};


#endif 
