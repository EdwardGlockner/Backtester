#include <iostream>
#include "event.h"

int main() {
	std::cout << "Hello World" << std::endl;
	OrderEvent Order("GOOG", "FX", 6, "UP");
	Order.print_order();	
	return 0;
}
