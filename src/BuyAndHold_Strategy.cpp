#include "BuyAndHold_Strategy.h"

BuyAndHold_Strategy :: BuyAndHold_Strategy(std::string in_bars, std::string in_events) {
	bars = in_bars;
	events = in_events;
	bought = calculate_initial_bought();

}

BuyAndHold_Strategy :: ~BuyAndHold_Strategy() {

}

std::map <std::string, bool> BuyAndHold_Strategy :: calculate_initial_bought() {
	std::map <std::string, bool> initial_bought;
	for (int i = 0; i < symbol_list.size(); i++) {
		initial_bought[symbol_list[i]] = false;
	}

	return initial_bought;

}

void BuyAndHold_Strategy :: calculate_signals() {

}



