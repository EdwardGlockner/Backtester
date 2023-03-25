#ifndef EVENT
#define EVENT

#include <iostream>
class Event {
	public:
		Event();
		~Event();

	private:

};

class MarketEvent {
	public: 
		MarketEvent();
		~MarketEvent();
		std::string type;

	private:

};

class SignalEvent {
	public:
		SignalEvent(std::string symbol, std::string datetime, std::string signal_type);
		/* fix to datetime type*/
		~SignalEvent();
		std::string type;
		std::string symbol;
		std::string datetime;
		std::string signal_type;
	
	private:

};

class OrderEvent {
	public:
		OrderEvent(std::string symbol, std::string order_type, int quantity, std::string direction);
		~OrderEvent();
		std::string type;
		std::string symbol;
		std::string order_type;
		int quantity;
		std::string direction;
		void print_order(); 

	private:

};

class FillEvent {
	public:
		FillEvent(std::string timeindex, std::string symbol, std::string exchange, int quantity, std::string direction, double fill_cost, std::string commision);
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
