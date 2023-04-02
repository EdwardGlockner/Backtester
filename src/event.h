#ifndef EVENT
#define EVENT

#include <iostream>
class Event {
	public:
		Event();
		~Event();
		std::string type;

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
		SignalEvent(std::string in_symbol, std::string in_datetime, std::string in_signal_type);
		/* fix to datetime type*/
		~SignalEvent();
		std::string type;
		std::string symbol;
		std::string datetime;
		std::string signal_type;
	
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
