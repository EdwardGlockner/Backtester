#ifndef EXECUTION
#define EXECUTION

#include <iostream>
#include "event.h"

class ExecutionHandler {
	public:
		ExecutionHandler();
		~ExecutionHandler();

		void execute_order();

	private:

};

class SimulatedExecutionHandler : public ExecutionHandler {
	public:
		SimulatedExecutionHandler(std::string in_events);
		~SimulatedExecutionHandler();
		std::string events;

		void execute_order(Event* event);

	private:


};



#endif
