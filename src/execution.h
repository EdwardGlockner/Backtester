/*

*/

#ifndef EXECUTION
#define EXECUTION

#include <iostream>
#include "event.h"

class ExecutionHandler {
	/*

	*/

	public:
		// Constructors and destructors
		ExecutionHandler();
		~ExecutionHandler();

		// Methods
		void execute_order();
};

class SimulatedExecutionHandler : public ExecutionHandler {
	/*

	*/

	public:
		// Constructors and destructors
		SimulatedExecutionHandler();
		SimulatedExecutionHandler(std::string in_events);
		~SimulatedExecutionHandler();

		// Methods
		void execute_order(Event* event);

		// Members
		std::string events;

};

#endif
