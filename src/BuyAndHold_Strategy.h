#ifndef BUYANDHOLD_STRATEGY
#define BUYANDHOLD_STRATEGY
#include "strategy_base.h"

class BuyAndHold_Strategy : public Strategy_Base {
	public:
		BuyAndHold_Strategy(std::string in_bars, std::string in_events);
		~BuyAndHold_Strategy();
		void calculate_initial_bought();
		void calculate_signals();

		std::string bars;
		std::string symbol_list;
		std::string events;


	private:
};

#endif
