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
		~SignalEvent();
		std::string type;
		std::string symbol;
		std::string datetime;
		std::string signal_type;
	
	private:

};

class OrderEvent {
	public:
		OrderEvent(std::string symbol, std::string order_type, std::string quantity, std::string direction);
		~OrderEvent();
		std::string type;
		std::string symbol;
		std::string order_type;
		std::string quantity;
		std::string direction;
		void print_order(); 

	private:

};

class FillEvent {
	public:
		FillEvent(std::string timeindex, std::string symbol, std::string exchange, std::string quantity, std::string direction, std::string fill_cost, std::string, std::string commission);
		~FillEvent();
		double calculate_ib_commision();
	
	private:

};
#endif
