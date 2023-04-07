/*

*/

#ifndef PORTFOLIO
#define PORTFOLIO

#include "event.h"
#include "data.h"

class Portfolio {
	/*

	*/

	public:
		// Constructors and destructors
		Portfolio();
		~Portfolio();

		// Methods
		void update_signal(Event event);
		void update_fill(Event event);
};

class NaivePortfolio : public Portfolio{
	/*

	*/

	public:
		// Constructors and destructors
		NaivePortfolio();
		NaivePortfolio(HistoricCSVDataHandler in_bars, std::queue <Event> in_events, std::string in_start_date, float in_initial_capital = 1000000);
		~NaivePortfolio();

		// Methods
		std::vector<std::map<std::string, std::string> > construct_all_positions();
		std::map<std::string, std::string> construct_current_positions();
		std::vector<std::map<std::string, std::string> > construct_all_holdings();
		std::map<std::string, std::string> construct_current_holdings();
		void update_time_index(Event event);
		void update_positions_from_fill(Event* event);
		void update_holdings_from_fill(Event* event);
		void update_fill(Event* event);
		OrderEvent generate_naive_order(Event* event);
		void update_signal(Event* event);
	
		// Members
		HistoricCSVDataHandler data_handler;	
		HistoricCSVDataHandler bars;
	       	std::queue<Event> events;
		std::string start_date;	
		std::vector<std::string> symbol_list;
		std::vector<std::map<std::string, std::string> > all_positions;
		std::map<std::string, std::string> current_positions;
		std::vector<std::map<std::string, std::string> > all_holdings;
		std::map<std::string, std::string> current_holdings;
		float initial_capital;
};

#endif 
