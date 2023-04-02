#ifndef BUYANDHOLD_STRATEGY
#define BUYANDHOLD_STRATEGY

#include "strategy_base.h"
#include "event.h"
#include "data.h"
#include <map>
#include <vector>

class BuyAndHold_Strategy : public Strategy_Base {
	public:
		BuyAndHold_Strategy(HistoricCSVDataHandler in_bars, Event in_events);
		~BuyAndHold_Strategy();
		std::map <std::string, bool> calculate_initial_bought();
		void calculate_signals(Event event);

		HistoricCSVDataHandler bars;
		std::vector <std::string> symbol_list;
		Event events;

		std::map <std::string, bool> bought;


	private:
};

#endif
