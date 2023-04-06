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


void backtest(Event events, HistoricCSVDataHandler data, Portfolio portfolio, BuyAndHold_Strategy strategy) {
	bool running = true;
	while (running) {
		data.update_bars("test");
	
	
	}
}

int main() {
	std::queue<Event> events;
	std::vector<Event> eventss;
	std::vector<std::string> symbol_list(1, "TSLA");
	Event eventtt;

	HistoricCSVDataHandler data = HistoricCSVDataHandler("test", "test", symbol_list);
	NaivePortfolio portfolio = NaivePortfolio(data, eventss, "test", 1000000);
	BuyAndHold_Strategy strategy = BuyAndHold_Strategy(data, eventtt);


	backtest();

	return 0;	
	

}
