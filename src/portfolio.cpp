#include "portfolio.h"

Portfolio::Portfolio() {

}

Portfolio::~Portfolio() {

}

void Portfolio::update_signal(Event event) {

}

void Portfolio::update_fill(Event event) {

}

NaivePortfolio::NaivePortfolio(std::vector<HistoricCSVDataHandler::Bar> in_bars, std::vector<Event> in_events, std::string in_start_date, float in_initial_capital) {

	bars = in_bars;
	events = in_events;
	start_date = in_start_date;
	initial_capital = in_initial_capital;
	symbol_list = create_symbol_list();
	all_positions = construct_all_positions();
	current_positions = construct_current_positions();
	all_holdings = construct_all_holdings();
}

NaivePortfolio::~NaivePortfolio() {

}

std::vector<std::map<std::string, std::string> > NaivePortfolio::construct_all_positions() {

	std::vector<std::map<std::string, std::string> > positions;
	
	for (int i = 0; i < symbol_list.size(); i++) {
		std::map<std::string, std::string> position;
		position[symbol_list[i]] = "0";
		positions.push_back(position);
	}

	std::map<std::string, std::string> date_val;
	date_val["datetime"] = start_date;
	positions.push_back(date_val);
	
	return positions;
}


std::map<std::string, std::string> NaivePortfolio::construct_current_positions() {
	
	std::map<std::string, std::string> positions;

	for (int i = 0; i < symbol_list.size(); i++) {
		positions[symbol_list[i]] = "0";
	}

	return positions;

}

std::vector<std::map<std::string, std::string> > NaivePortfolio::construct_all_holdings() {

	std::vector< std::map<std::string, std::string> > holdings;
	for (int i = 0; i < symbol_list.size(); i++) {
		std::map<std::string, std::string> holding;
		holding[symbol_list[i]] = "0";
		holdings.push_back(holding);
	}
	std::map<std::string, std::string> date_val;
	std::map<std::string, std::string> cash_val;
	std::map<std::string, std::string> commision_val;
	std::map<std::string, std::string> total_val;

	date_val["datetime"] = start_date;
	cash_val["cash"] = std::to_string(initial_capital);
	commision_val["commision"] = "0.0";
	total_val["total"] = std::to_string(initial_capital);

	holdings.push_back(date_val);
	holdings.push_back(cash_val);
	holdings.push_back(commision_val);
	holdings.push_back(total_val);

	return holdings;
}

std::map<std::string, std::string> NaivePortfolio::construct_current_holdings() {
	// should return map, not vector
	std::map<std::string, std::string> holdings;
	for (int i = 0; i < symbol_list.size(); i++) {
		holdings[symbol_list[i]] = "0";
	}

	holdings["cash"] = std::to_string(initial_capital);
	holdings["commision"] = std::to_string(0.01); // change
	holdings["total"] = std::to_string(initial_capital);

	return holdings;


}

void NaivePortfolio::update_time_index() {

}

void NaivePortfolio::update_positions_from_fill() {

}

void NaivePortfolio::update_holdings_from_fill() {

}

void NaivePortfolio::update_fill() {

}

OrderEvent NaivePortfolio::generate_naive_order(Event* event) {
	OrderEvent ord_evt("", "", 0, "");
	if (event->type == Event::SIGNAL_EVENT) {
		SignalEvent* sig_evt = static_cast<SignalEvent*>(event);
		
		std::string symbol = sig_evt -> symbol;
		std::string direction = sig_evt -> signal_type;
		float strength = sig_evt -> strength;

		int mkt_quantity = static_cast<int>(100 * strength);
		int cur_quantity = std::stoi(current_positions[symbol]);
		std::string order_type = "MKT";

		if (direction == "LONG" && cur_quantity == 0) {
			OrderEvent ord_evt(symbol, order_type, mkt_quantity, "BUY");
		}
		else if (direction == "SHORT" && cur_quantity == 0) {
			OrderEvent ord_evt(symbol, order_type, mkt_quantity, "SELL");
		}
		else if (direction == "EXIT" && cur_quantity > 0) {
			OrderEvent ord_evt(symbol, order_type, mkt_quantity, "SELL");	
		}
		else if (direction == "EXIT" && cur_quantity < 0) {
			OrderEvent ord_evt(symbol,order_type, mkt_quantity, "BUY");
		}

	}
	else {
	
	}

	return ord_evt;

}

void NaivePortfolio::update_signal(Event* event) {
	if (event->type == Event::SIGNAL_EVENT) {
		SignalEvent* new_event = static_cast<SignalEvent*>(event);
		OrderEvent ord_evt = generate_naive_order(new_event);
		//self.events.put(ord_evt)
	}
	else {
	
	}

}

std::vector<std::string> NaivePortfolio::create_symbol_list() {
	std::vector<std::string> list;
	// Extract symbols from MyStruct vector
  	for (int i = 0; i < bars.size(); i++) {
    		list.push_back(bars[i].Symbol);
  	}

	return list;
}
