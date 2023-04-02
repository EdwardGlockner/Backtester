#include "performance.h"
#include <cmath>

Performance::Performance(const std::vector<float>& in_returns) {
	returns = in_returns;
	sharpe_ratio = create_sharpe_ratio();
	drawdowns = create_drawdowns();
	volatility = create_volatility();

}

Performance::~Performance() {


}

float Performance::create_sharpe_ratio() {
	int n = returns.size();
       	float avg_return = 0.0f;

	for (std::vector<float>::const_iterator it = returns.begin(); it != returns.end(); ++it) {
    		const float& r = *it;
    		avg_return += r;
	}

	avg_return /= n;
	float std_dev = 0.0f;

	for (std::vector<float>::const_iterator it = returns.begin(); it != returns.end(); ++it) {
    		const float& r = *it;
    		std_dev += std::pow(r - avg_return, 2);
	}

	std_dev /= n;
	std_dev = std::sqrt(std_dev);
	float sharpe = (avg_return - 0.0f) / std_dev;
	return sharpe;
}

float Performance::create_drawdowns() {

	return 0;
}

float Performance::create_volatility() {

	return 0;
}

void create_pdf_report() {

}

void HTML_display_report() {

}
