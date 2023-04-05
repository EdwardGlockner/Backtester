#ifndef EVENT
#define EVENT

#include <iostream>
class Event {
	public:
		Event();
		~Event();
		enum EventType {MARKET_EVENT, SIGNAL_EVENT, ORDER_EVENT, FILL_EVENT};
		EventType type;

	private:

};

class MarketEvent : public Event {
	public: 
		MarketEvent();
		~MarketEvent();
		std::string type;

	private:

};

class SignalEvent : public Event {
	public:
		SignalEvent(std::string in_symbol, std::string in_datetime, std::string in_signal_type, float in_strength);
		/* fix to datetime type*/
		~SignalEvent();
		std::string type;
		std::string symbol;
		std::string datetime;
		std::string signal_type;
		float strength;
	
	private:

};

class OrderEvent : public Event {
	public:
		OrderEvent(std::string in_symbol, std::string in_order_type, int in_quantity, std::string in_direction);
		~OrderEvent();
		std::string type;
		std::string symbol;
		std::string order_type;
		int quantity;
		std::string direction;
		void print_order(); 

	private:

};

class FillEvent :public Event {
	public:
		FillEvent(std::string in_timeindex, std::string in_symbol, std::string in_exchange, int in_quantity, std::string in_direction, double in_fill_cost, std::string in_commision);
		~FillEvent();
		std::string type;
		std::string timeindex;
		std::string symbol;
		std::string exchange;
		int quantity;
		std::string direction;
		double fill_cost;
		std::string commision;
		double calc_ib_commision();
	
	private:

};
#endif
