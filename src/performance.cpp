#include "performance.h"
#include <cmath>
#include <unistd.h>
#include <iostream>

Performance::Performance(const std::vector<float>& in_returns) {
	returns = in_returns;
	sharpe_ratio = create_sharpe_ratio();
	drawdowns = create_drawdowns();
	volatility = create_volatility();

}

Performance::~Performance() {


}

/* 
 * periods - Daily (252), Hourly (252*6.5), Minutely(252*6.5*60) etc.
 */
float Performance::create_sharpe_ratio(int periods) {
	float sum = 0.0f;
    	for (float num : returns) {
        	sum += num;
    	}
    	float mean = sum / static_cast<float>(vec.size());

	sr = sqrt(periods) * 
	return sr;
}

float Performance::create_drawdowns() {

	return 0;
}

float Performance::create_volatility() {

	return 0;
}

void create_pdf_report() {
	const char* relative_path = "../Reports/stock_report.py";
	std::string command = "python3 " + std::string(relative_path);
	std::system(command.c_str());

}

void HTML_display_report() {

}
