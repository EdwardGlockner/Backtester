/*

*/

#include "event.h"


/* CLASS EVENT */ 
Event::Event() {
	/*

	*/

} 


Event::~Event() {
	/*

	*/

}


/* CLASS MARKETEVENT */
MarketEvent::MarketEvent() {
	/*

	*/
	type = "MARKET_EVENT";
}


MarketEvent::~MarketEvent() {
	/*

	*/

}


/* CLASS SIGNALEVENT */
SignalEvent::SignalEvent() {
	/*

	*/

}


SignalEvent::SignalEvent(std::string in_symbol, std::string in_datetime, std::string in_signal_type, float in_strength) {
	/*

	*/

	type = "SIGNAL_EVENT";
	symbol = in_symbol;
	datetime = in_datetime;
	signal_type = in_signal_type;
	strength = in_strength;
}


SignalEvent::~SignalEvent() {
	/*

	*/

}


/* CLASS ORDEREVENT */
OrderEvent::OrderEvent() {
	/*

	*/

}


OrderEvent::OrderEvent(std::string in_symbol, std::string in_order_type, int in_quantity, std::string in_direction) {
	/*

	*/

	type = "ORDER_EVENT";
	symbol = in_symbol;
	order_type = in_order_type;
	quantity = in_quantity;
	direction = in_direction;
}


OrderEvent::~OrderEvent() {
	/*

	*/

}


void OrderEvent::print_order() {
	/*

	*/

	std::cout << "Order: Symbol=" << symbol << ", Type=" << type << ", Quantity=" << quantity << ", Direction=" << direction << std::endl;
}


/* CLASS FILLEVENT */
FillEvent::FillEvent() {
	/*

	*/

}


FillEvent::FillEvent(std::string in_timeindex, std::string in_symbol, std::string in_exchange, int in_quantity, std::string in_direction, double in_fill_cost, std::string in_commision) {
	/*

	*/

	type = "FILL_EVENT";
	timeindex = in_timeindex;
	symbol = in_symbol;
	exchange = in_exchange;
	quantity = in_quantity;
	direction = in_direction;
	fill_cost = in_fill_cost;
	commision = in_commision;
}


FillEvent::~FillEvent() {
	/*

	*/

}


double FillEvent::calc_ib_commision() {
	/*

	*/

	double full_cost = 1.3;
	if (quantity <= 500) {
		if (0.013*quantity <= 1.3) {
			full_cost = 1.3;
		}
		else {
			full_cost = 0.013*quantity;
		}
	}
	else {
		if (0.008*quantity <= 1.3) {
			full_cost = 1.3;
		}
		else {
			full_cost = 0.008*quantity;
		}
	}
	if (full_cost <= (0.5/100)*quantity*fill_cost) {
		full_cost = full_cost;
	}
	else {
		full_cost = (0.5/100)*quantity*fill_cost;
	}
	return full_cost;
}
