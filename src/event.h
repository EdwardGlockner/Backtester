/*

*/

#ifndef EVENT
#define EVENT

#include <iostream>

class Event {
	/*

	*/
	public:
		// Constructors and destructors
		Event();
		~Event();

		// Members
		enum EventType {MARKET_EVENT, SIGNAL_EVENT, ORDER_EVENT, FILL_EVENT};
		EventType type;
};

class MarketEvent : public Event {
	/*

	*/

	public: 
		// Constructors and destructors
		MarketEvent();
		~MarketEvent();

		// Members
		std::string type;
};

class SignalEvent : public Event {
	/*

	*/

	public:
		// Constructors and destructors
		SignalEvent();
		SignalEvent(std::string in_symbol, std::string in_datetime, std::string in_signal_type, float in_strength);
		~SignalEvent();

		// Members
		std::string type;
		std::string symbol;
		std::string datetime;
		std::string signal_type;
		float strength;
};

class OrderEvent : public Event {
	/*

	*/

	public:
		// Constructors and destructors
		OrderEvent();
		OrderEvent(std::string in_symbol, std::string in_order_type, int in_quantity, std::string in_direction);
		~OrderEvent();

		// Methods
		void print_order(); 

		// Members
		std::string type;
		std::string symbol;
		std::string order_type;
		int quantity;
		std::string direction;
};

class FillEvent : public Event {
	/*

	*/

	public:
		// Constructors and destructors
		FillEvent();
		FillEvent(std::string in_timeindex, std::string in_symbol, std::string in_exchange, int in_quantity, std::string in_direction, double in_fill_cost, std::string in_commision);
		~FillEvent();

		// Methods
		double calc_ib_commision();

		// Members
		std::string type;
		std::string timeindex;
		std::string symbol;
		std::string exchange;
		int quantity;
		std::string direction;
		double fill_cost;
		std::string commision;

};
#endif
