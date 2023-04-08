/*

*/

#include "execution.h"

ExecutionHandler :: ExecutionHandler() {
	/*

	*/

}


ExecutionHandler :: ~ExecutionHandler() {
	/*

	*/
}


SimulatedExecutionHandler :: SimulatedExecutionHandler() {
	/*

	*/

}


SimulatedExecutionHandler :: SimulatedExecutionHandler(std::queue<Event> in_events) {
	/*

	*/
	events = in_events;
}


SimulatedExecutionHandler :: ~SimulatedExecutionHandler() {
	/*

	*/
}


void SimulatedExecutionHandler :: execute_order(Event* event) {
	/*

	*/
	if (event->type == Event::ORDER_EVENT) {
		// Use static_cast to cast the Event pointer to 
		// a OrderEvent pointer if the type is ORDER_EVENT
		FillEvent* new_event = static_cast<FillEvent*>(event);
		FillEvent fill_event("time", new_event->symbol, "SIMULATED", new_event->quantity, new_event->direction,0.0, "");
		//self.events.put(fill_event) // que
	}
	else {

	}
}
