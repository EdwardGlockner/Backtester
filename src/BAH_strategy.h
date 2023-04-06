/*

*/

#ifndef BUYANDHOLD_STRATEGY
#define BUYANDHOLD_STRATEGY

#include "strategy_base.h"
#include "event.h"
#include "data.h"
#include <map>
#include <vector>

class BuyAndHold_Strategy : public Strategy_Base {
	/*

	*/
	public:
		// Constructors and destructors
		BuyAndHold_Strategy();
		BuyAndHold_Strategy(HistoricCSVDataHandler in_bars, std::queue<Event> in_events);
		~BuyAndHold_Strategy();
		
		// Methods
		std::map <std::string, bool> calculate_initial_bought();
		void calculate_signals(Event* event);
		
		// Members
		HistoricCSVDataHandler bars;
		std::vector <std::string> symbol_list;
		std::queue<Event> events;
		std::map <std::string, bool> bought;
};

#endif
