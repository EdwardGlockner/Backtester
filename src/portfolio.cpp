/*

*/

#include "portfolio.h"

Portfolio::Portfolio() {
	/*

	*/

}


Portfolio::~Portfolio() {
	/*

	*/
}


void Portfolio::update_signal(Event event) {
	/*

	*/

}


void Portfolio::update_fill(Event event) {
	/*

	*/
}


NaivePortfolio::NaivePortfolio() {
	/*

	*/

}


NaivePortfolio::NaivePortfolio(HistoricCSVDataHandler in_bars, std::queue<Event> in_events, std::string in_start_date, float in_initial_capital) {
	/*

	*/

	bars = in_bars;
	events = in_events;
	start_date = in_start_date;
	initial_capital = in_initial_capital;
	symbol_list = bars.symbol_list;
	all_positions = construct_all_positions();
	current_positions = construct_current_positions();
	all_holdings = construct_all_holdings();
}


NaivePortfolio::~NaivePortfolio() {
	/*

	*/

}


std::vector<std::map<std::string, std::string> > NaivePortfolio::construct_all_positions() {
	/*

	*/

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
	/*

	*/
	
	std::map<std::string, std::string> positions;

	for (int i = 0; i < symbol_list.size(); i++) {
		positions[symbol_list[i]] = "0";
	}

	return positions;
}


std::vector<std::map<std::string, std::string> > NaivePortfolio::construct_all_holdings() {
	/*

	*/

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
	/*

	*/

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


void NaivePortfolio::update_time_index(Event event) {
	/*

	*/

	std::map<std::string, HistoricCSVDataHandler::Bar> temp_bars;
	for (int i = 0; i < symbol_list.size(); i++) {
		temp_bars[symbol_list[i]] = bars.get_latest_bars(symbol_list[i], 1);
	}	

	std::map<std::string, std::string> dp;
	dp = construct_current_positions();	
	dp["datetime"] = temp_bars[symbol_list[0]].DateTime;

	for (int i = 0; i < symbol_list.size(); i++) {
		dp[symbol_list[i]] = current_positions[symbol_list[i]];
	}

	all_positions.push_back(dp);

	std::map<std::string, std::string> dh;
	dh = construct_current_positions();
	dh["datetime"] = temp_bars[symbol_list[0]].DateTime;
	dh["cash"] = current_holdings["cash"];
	dh["commision"] = current_holdings["commision"];
	dh["total"] = current_holdings["total"];

	for (int i = 0; i < symbol_list.size(); i++) {
		float market_value = std::stof(current_positions[symbol_list[i]]) * temp_bars[symbol_list[i]].Close;
		dh[symbol_list[i]] = market_value;
		dh["total"] += market_value;
	}
	all_holdings.push_back(dh);
}


void NaivePortfolio::update_positions_from_fill(Event* event) {
	/*

	*/

	if (event->type == Event::FILL_EVENT) {
		FillEvent* fill_evt = static_cast<FillEvent*>(event);
		int fill_dir = 0;
		if (fill_evt-> direction == "BUY") {
			fill_dir = 1;
		}
		else if (fill_evt-> direction == "SELL") {
			fill_dir = -1;
		}
		current_positions[fill_evt->symbol] += fill_dir*fill_evt->quantity;
	}
}


void NaivePortfolio::update_holdings_from_fill(Event* event) {
	/*

	*/

	if (event->type == Event::FILL_EVENT) {
		FillEvent* fill_evt = static_cast<FillEvent*>(event);
		int fill_dir = 0;
		if (fill_evt->direction == "BUY") {
			fill_dir = 1;
		}
		else if (fill_evt->direction == "SELL") {
			fill_dir = -1;
		}
		float fill_cost = bars.get_latest_bars(fill_evt->symbol, 1).Close;
		float cost = fill_dir * fill_cost * fill_evt->quantity;

		current_holdings[fill_evt->symbol] += cost;
		current_holdings["commision"] += fill_evt->commision;
		current_holdings["cash"] = std::stof(current_holdings["cash"]) - (cost + std::stof(fill_evt->commision));
		current_holdings["total"] = std::stof(current_holdings["total"]) - (cost + std::stof(fill_evt->commision));
	}
}


void NaivePortfolio::update_fill(Event* event) {
	/*

	*/

	if (event->type == Event::FILL_EVENT) {
		FillEvent* fill_evt = static_cast<FillEvent*>(event);
		update_positions_from_fill(fill_evt);
		update_holdings_from_fill(fill_evt);
	}
}


OrderEvent NaivePortfolio::generate_naive_order(Event* event) {
	/*

	*/

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
	/*

	*/

	if (event->type == Event::SIGNAL_EVENT) {
		SignalEvent* new_event = static_cast<SignalEvent*>(event);
		OrderEvent ord_evt = generate_naive_order(new_event);
		//self.events.put(ord_evt)
	}
	else {
	
	}
}


