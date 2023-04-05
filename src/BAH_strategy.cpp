#include "BAH_strategy.h"


BuyAndHold_Strategy::BuyAndHold_Strategy(HistoricCSVDataHandler in_bars, Event in_events) {
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

void BuyAndHold_Strategy :: calculate_signals(Event* event) {
	if (event->type == Event::MARKET_EVENT) {
		for (int i = 0; i < symbol_list.size(); i++) {
			struct HistoricCSVDataHandler::Bar latest_bars("", "",0,0,0,0,0);
			latest_bars = bars.get_latest_bars(symbol_list[i], 1);
			if (bought[symbol_list[i]] == false) {
				SignalEvent signal(latest_bars.Symbol, latest_bars.DateTime, "LONG", 1);
				//events.put(signal); should be <queue>
				bought[symbol_list[i]] = true;
			}	
		}
	}
}



