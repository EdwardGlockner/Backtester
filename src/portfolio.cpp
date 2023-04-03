#include "portfolio.h"

Portfolio::Portfolio() {

}

Portfolio::~Portfolio() {

}

void Portfolio::update_signal(Event event) {

}

void Portfolio::update_fill(Event event) {

}

NaivePortfolio::NaivePortfolio(std::string in_bars, std::string in_events, std::string in_start_date, float in_initial_capital) {
	bars = in_bars;
	events = in_events;
	start_date = in_start_date;
	initial_capital = in_initial_capital;

}

NaivePortfolio::~NaivePortfolio() {

}

void NaivePortfolio::construct_all_positions() {

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
