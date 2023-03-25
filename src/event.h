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
		SignalEvent();
		~SignalEvent();
		std::string type;
		std::string symbol;
		std::string datetime;
		std::string signal_type;
	
	private:

};

class OrderEvent {
	public:
		OrderEvent();
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
		FillEvent();
		~FillEvent();
		double calculate_ib_commision();
	
	private:

};
#endif
