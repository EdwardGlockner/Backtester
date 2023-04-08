/*

*/
#include "Event/event.h"
#include "Data/data.h"
#include "Strategies/strategy_base.h"
#include "Strategies/BAH_strategy.h"
#include "Execution/execution.h"
#include "Performance/performance.h"
#include "Portfolio/portfolio.h"

#include <iostream>
#include <unistd.h>
#include <queue>
#include <vector>


void backtest(std::queue<Event> events, HistoricCSVDataHandler data, NaivePortfolio portfolio, BuyAndHold_Strategy strategy, SimulatedExecutionHandler broker) {
	
	bool running = true;
	while (running) {
		data.update_bars("TSLA");
		std::cout<<"here"<<std::endl;
		if (!data.continue_backtest) {
			running = false;
		}
		/*
		while (true) {
			if (events.empty()) {
				break;
			}
			Event event = events.front();
			events.pop();
			if (true) { // check if the event is null or not
				if (event.type == Event::MARKET_EVENT) {
					strategy.calculate_signals(&event);	
					portfolio.update_time_index(event);
				}
				else if (event.type == Event::SIGNAL_EVENT) {
					portfolio.update_signal(&event);
				
				}
				else if (event.type == Event::ORDER_EVENT) {
					broker.execute_order(&event);
				
				}
				else if (event.type == Event::FILL_EVENT) {
					portfolio.update_fill(&event);
				}
			}
		}
		*/
		running = false;
	}
	
}

int main() {
	std::queue<Event> events;
	std::vector<std::string> symbol_list(1, "TSLA");

	HistoricCSVDataHandler data = HistoricCSVDataHandler(events, "/Users/edwardglockner/OneDrive - Uppsala universitet/Big Python Projects/Backtester/data/YahooData/data/TSLA_1m.csv", symbol_list);
	NaivePortfolio portfolio = NaivePortfolio(data, events, "date", 1000000);
	BuyAndHold_Strategy strategy = BuyAndHold_Strategy(data, events);
	SimulatedExecutionHandler broker = SimulatedExecutionHandler(events);

	std::cout<<"Program starts!"<<std::endl;
	backtest(events, data, portfolio, strategy, broker);
	std::cout<<"Program ends!"<<std::endl;

	return 0;	
}
