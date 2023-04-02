#ifndef BUYANDHOLD_STRATEGY
#define BUYANDHOLD_STRATEGY
#include "strategy_base.h"
#include <map>
#include <vector>

class BuyAndHold_Strategy : public Strategy_Base {
	public:
		BuyAndHold_Strategy(std::string in_bars, std::string in_events);
		~BuyAndHold_Strategy();
		std::map <std::string, bool> calculate_initial_bought();
		void calculate_signals();

		std::string bars;
		std::vector <std::string> symbol_list;
		std::string events;

		std::map <std::string, bool> bought;


	private:
};

#endif
