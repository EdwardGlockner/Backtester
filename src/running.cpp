#include "event.h"
#include "data.h"
#include "strategy_base.h"
#include "BAH_strategy.h"
#include "execution.h"
#include "performance.h"
#include "portfolio.h"

#include <iostream>
#include <unistd.h>
#include <queue>
#include <vector>


void backtest(std::queue<Event> events, HistoricCSVDataHandler data, Portfolio portfolio, BuyAndHold_Strategy strategy, SimulatedExecutionHandler broker) {
	bool running = true;
	while (running) {
		data.update_bars("test");
		if (!data.continue_backtest) {
			running = false;
		}
		while (true) {
			if (events.empty()) {
				break;
			}
			Event event = events.front();
			events.pop();
			if (true) { // check if the event is null or not
				if (event.type == Event::MARKET_EVENT) {
					strategy.calculate_signals(event);	
					portfolio.update_timeindex(event);
				}
				else if (event.type == Event::SIGNAL_EVENT) {
					portfolio.update_signal(event);
				
				}
				else if (event.type == Event::ORDER_EVENT) {
					broker.execute_order(event);
				
				}
				else if (event.type == Event::FILL_EVENT) {
					portfolio.update_fill(event);
				}
			}
		}
	}
}

int main() {
	std::queue<Event> events;
	std::vector<Event> eventss;
	std::vector<std::string> symbol_list(1, "TSLA");
	Event eventtt;

	HistoricCSVDataHandler data = HistoricCSVDataHandler(events, "/Users/edwardglockner/OneDrive - Uppsala universitet/Big Python Projects/Backtester/Data/YahooData/data/TSLA_2023-03-25_1m", symbol_list);
	NaivePortfolio portfolio = NaivePortfolio(data, events, "date", 1000000);
	BuyAndHold_Strategy strategy = BuyAndHold_Strategy(data, events);
	SimulatedExecutionHandler broker = SimulatedExecutionHandler(events);

	std::cout<<"Program starts!"<<std::endl;

	backtest(events, data, portfolio, strategy, broker);

	/*
	events = queue.Queue()
	data = HistoricCSVDataHandler(events, 'csv/', ['OMXS30'], DataSource.NASDAQ)
	portfolio = NaivePortfolio(data, events, '', initial_capital=2000)
	strategy = MovingAveragesLongStrategy(data, events, portfolio, 50, 100, version=1)
	portfolio.strategy_name = strategy.name
	broker = SimulateExecutionHandler(events)
	 */
	return 0;	
}
/*
    stats = portfolio.summary_stats()

    for stat in stats:
            print(stat[0] + ": " + stat[1])

    strategy.plot()
    portfolio.plot_all()

  */
