#include "BuyAndHold_Strategy.h"

BuyAndHold_Strategy :: BuyAndHold_Strategy(HistoricCSVDataHandler in_bars, Event in_events) {
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

void BuyAndHold_Strategy :: calculate_signals(Event event) {
	if (event.type == "MARKET") {
		for (int i = 0; i < symbol_list.size(); i++) {
			latest_bars = bars.get_latest_bars();
			if (bought[i] == false) {
				SignalEvent signal(bars[0][0], bars[0][1], "LONG");
				events.put(signal);
				bought[i] = true;
			}	
		}
	}
}



