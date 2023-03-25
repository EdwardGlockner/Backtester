#include "event.h"


/* CLASS EVENT */ 
Event::Event() {

} 

Event::~Event() {

}

/* CLASS MARKETEVENT */
MarketEvent::MarketEvent() {
	type = "MARKET";
}

MarketEvent::~MarketEvent() {

}

/* CLASS SIGNALEVENT */
SignalEvent::SignalEvent(std::string symbol, std::string datetime, std::string signal_type) {
	type = "SIGNAL";
	symbol = symbol;
	datetime = datetime;
	signal_type = signal_type;
}

SignalEvent::~SignalEvent() {

}

/* CLASS ORDEREVENT */
OrderEvent::OrderEvent(std::string symbol, std::string order_type, int quantity, std::string direction) {
	type = "ORDER";
	symbol = symbol;
	order_type = order_type;
	quantity = quantity;
	direction = direction;
}

OrderEvent::~OrderEvent() {

}

void OrderEvent::print_order() {
	std::cout << "Order: Symbol=" << symbol << ", Type=" << type << ", Quantity=" << quantity << ", Direction=" << direction << std::endl;
}

/* CLASS FILLEVENT */
FillEvent::FillEvent(std::string timeindex, std::string symbol, std::string exchange, int quantity, std::string direction, double fill_cost, std::string commision) {
	type = "FILL";
	timeindex = timeindex;
	symbol = symbol;
	exchange = exchange;
	quantity = quantity;
	direction = direction;
	fill_cost = fill_cost;
	commision = commision;
}

FillEvent::~FillEvent() {

}

double FillEvent::calc_ib_commision() {
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
