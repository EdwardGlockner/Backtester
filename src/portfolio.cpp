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

std::vector<std::map<std::string, std::string> > NaivePortfolio::construct_current_positions() {
	std::vector<std::map<std::string, std::string> > positions;

	for (int i = 0; i < symbol_list.size(); i++) {
		std::map<std::string, std::string> position;
		position[symbol_list[i]] = "0";
		positions.push_back(position);
	}

	return positions;

}

void NaivePortfolio::construct_all_holdings() {

}

void NaivePortfolio::construct_current_holdings() {

}

void NaivePortfolio::update_time_index() {

}

void NaivePortfolio::update_positions_from_fill() {

}

void NaivePortfolio::update_holdings_from_fill() {

}

void NaivePortfolio::update_fill() {

}

void NaivePortfolio::generate_naive_order() {

}

void NaivePortfolio::update_signal() {

}

void NaivePortfolio::create_equity_curve_dataframe() {

}

std::vector<std::string> NaivePortfolio::create_symbol_list() {
	std::vector<std::string> list;
	// Extract symbols from MyStruct vector
  	for (int i = 0; i < bars.size(); i++) {
    		list.push_back(bars[i].Symbol);
  	}

	return list;
}

