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
		if (!data.continue_backtest) {
			running = false;
		}
		std::cout << "aaa" << std::endl;

		// need to put events
		bool event_flow = true;	
		while (event_flow) {
			std::cout << "eawer" << std::endl;
			if (events.empty()) {
				event_flow = false;
			}
			Event event = events.front();
			events.pop();
				
			std::cout << "here" << std::endl;
			if (event.type == Event::MARKET_EVENT) {
				strategy.calculate_signals(&event);	
				portfolio.update_time_index(event);
				std::cout<< "here1" <<std::endl;
			}
			else if (event.type == Event::SIGNAL_EVENT) {
				portfolio.update_signal(&event);
				std::cout<< "here1" <<std::endl;

			}
			else if (event.type == Event::ORDER_EVENT) {
				broker.execute_order(&event);
				std::cout<< "here1" <<std::endl;

			}
			else if (event.type == Event::FILL_EVENT) {
				portfolio.update_fill(&event);
				std::cout<< "here1" <<std::endl;

			}
		}
		
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
