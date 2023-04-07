/*

*/

#include "performance.h"
#include <cmath>
#include <unistd.h>
#include <iostream>

Performance::Performance() {
	/*

	*/

}


Performance::Performance(const std::vector<float>& in_returns) {
	/*

	*/

	returns = in_returns;
	sharpe_ratio = create_sharpe_ratio();
	drawdowns = create_drawdowns();
	volatility = create_volatility();
	stddev = create_stddev();
	variance = create_variance();
	cum_returns = create_cum_returns();
}


Performance::~Performance() {
	/*

	*/
}


float Performance::create_sharpe_ratio(int periods) {
	/*
		periods - Daily(252), Hourly (252*6.5), Minutely(252*6.5*60) etc
	*/

	float mean = calc_mean();

	float stdDev = create_stddev();

	float sr = sqrt(periods) * (mean / stdDev); 
	return sr;
}

float Performance::create_drawdowns() {
	/*

	*/

	return 0;
}


float Performance::calc_mean() {
	/*

	*/

	float sum = 0.0f;
	for (int i = 0; i < returns.size(); i++) {
		sum += returns[i];
	}
	float mean = sum / static_cast<float>(returns.size());

	return mean;
}


float Performance::create_volatility(int period) {
	/*

	*/

	float sd = create_stddev();
	float vol = sd * sqrt(static_cast<float>(period));
	return vol;
}


float Performance::create_stddev() {
	/*

	*/

	float var = create_variance();
	float sd = sqrt(var);
	return sd;
}


float Performance::create_variance() {
	/*

	*/

	float mean = calc_mean();
	float sum = 0.0f;

	for (int i = 0; i<returns.size(); i++) {
		sum += (returns[i] - mean) * (returns[i] - mean);
	}

	float var = sum / static_cast<float>(returns.size() - 1);
	return var;
}


std::vector<float> Performance::create_cum_returns() {
	/*

	*/

	std::vector<float> cum_rets;
	float cum_ret = 1.0f;

	for (int i = 0; i < returns.size(); i++) {
    		cum_ret *= (1.0f + returns[i]);
    		cum_rets.push_back(cum_ret - 1.0f);
	}
	return cum_rets;
}


void create_pdf_report() {
	/*

	*/

	const char* relative_path = "../Reports/stock_report.py";
	std::string command = "python3 " + std::string(relative_path);
	std::system(command.c_str());

}


void HTML_display_report() {
	/*

	*/
}
