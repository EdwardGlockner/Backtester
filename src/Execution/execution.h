/*

*/

#ifndef EXECUTION
#define EXECUTION

#include <iostream>
#include <queue>
#include "../Event/event.h"

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
		SimulatedExecutionHandler(std::queue<Event> in_events);
		~SimulatedExecutionHandler();

		// Methods
		void execute_order(Event* event);

		// Members
		std::queue<Event> events;

};

#endif
