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

	HistoricCSVDataHandler data = HistoricCSVDataHandler(events, "test", symbol_list);
	NaivePortfolio portfolio = NaivePortfolio(data, events, "test", 1000000);
	BuyAndHold_Strategy strategy = BuyAndHold_Strategy(data, events);

	std::cout<<"Program starts!"<<std::endl;


	//backtest();
	

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

def backtest(events, data, portfolio, strategy, broker):
    while True:
        data.update_latest_data()
        if data.continue_backtest == False:
            break

        while True:
            try:
                event = events.get(block=False)
            except queue.Empty:
                break

            if event is not None:
                if event.type == 'MARKET':
                    strategy.calculate_signals(event)
                    portfolio.update_timeindex(event)
                elif event.type == 'SIGNAL':
                    portfolio.update_signal(event)
                elif event.type == 'ORDER':
                    broker.execute_order(event)
                elif event.type == 'FILL':
                    portfolio.update_fill(event)

        # time.sleep(10*60)
    stats = portfolio.summary_stats()

    for stat in stats:
            print(stat[0] + ": " + stat[1])

    strategy.plot()
    portfolio.plot_all()







  */
