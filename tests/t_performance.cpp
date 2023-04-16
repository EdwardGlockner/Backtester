/*

*/

#include "t_performance.h"

t_performance :: t_performance() {
	static const float arr[] = {-9,-8, -7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	std::vector <float> vec (arr, arr + sizeof(arr) / sizeof(arr[0]) );;
	t_returns = vec;

	t_mean = 0.0;
	t_stddev = 5.91608;
	t_variance = 35;
	static const float arr2[] = {-0.08, -0.15, -0.21, -0.26, -0.3, -0.33, -0.35, -0.36, -0.36, -0.35, -0.33, -0.3, -0.26, -0.21, -0.15, -0.08, 0.04, 0.13, 0.23};
	std::vector <float> vec2 (arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]) );;
	t_cum_returns = vec2;
	t_sharpe_ratio = -0.03376;
	t_drawdowns = 500;
	
	testing = Performance(t_returns);
	num_test = 0;
}


t_performance :: ~t_performance() {

}


void t_performance :: t_create_sharpe_ratio() {
	std::cout << testing.create_sharpe_ratio() << std::endl;
	std::cout << t_sharpe_ratio << std::endl;
	if (testing.create_sharpe_ratio() == t_sharpe_ratio) {
		std::cout << "Performance, test " << num_test << ": \t function {create_sharpe_ratio} passed test!" << std::endl;	
		++num_test;
	}
	else {
		std::cout << "Performance, test " << num_test << ": \t function {create_sharpe_ratio} FAILED test!" << std::endl;
	}	
}


void t_performance :: t_create_drawdowns() {
	if (testing.create_drawdowns() == t_drawdowns) {
		std::cout << "Performance, test " << num_test << ": \t function {create_drawdowns} passed test!" << std::endl;	
		++num_test;
	}
	else {
		std::cout << "Performance, test " << num_test << ": \t function {create_drawdowns} FAILED test!" << std::endl;
	}	

}


void t_performance :: t_create_volatility() {
	if (testing.create_volatility() == t_volatility) {
		std::cout << "Performance, test " << num_test << ": \t function {create_volatility} passed test!" << std::endl;	
		++num_test;
	}
	else {
		std::cout << "Performance, test " << num_test << ": \t function {create_volatility} FAILED test!" << std::endl;
	}	

}


void t_performance :: t_create_stddev() {
	if (testing.create_stddev() == t_stddev) {
		std::cout << "Performance, test " << num_test << ": \t function {create_stddev} passed test!" << std::endl;	
		++num_test;
	}
	else {
		std::cout << "Performance, test " << num_test << ": \t function {create_stddev} FAILED test!" << std::endl;
	}	

}


void t_performance :: t_create_variance() {
	std::cout << testing.create_variance() << std::endl;
	std::cout << t_variance << std::endl;
	if (testing.create_variance() == t_variance) {
		std::cout << "Performance, test " << num_test << ": \t function {create_variance} passed test!" << std::endl;	
		++num_test;
	}
	else {
		std::cout << "Performance, test " << num_test << ": \t function {create_variance} FAILED test!" << std::endl;
	}	

}


void t_performance :: t_create_cum_returns() {

}


void t_performance :: t_create_pdf_report() {

}


void t_performance :: t_HTML_display_report() {

}



void t_performance :: t_test_members() {

}

