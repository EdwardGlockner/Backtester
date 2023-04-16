/*

*/

#ifndef T_PERFORMANCE_H
#define T_PERFORMANCE_H

#include <iostream>
#include <vector>
#include "../src/Performance/performance.h"

class t_performance {
	public:
		// Constructors and destructors
		t_performance();
		~t_performance();

		// Methods
		void t_create_sharpe_ratio();
		void t_create_drawdowns();
		void t_create_volatility();
		void t_create_stddev();
		void t_create_variance();
		void t_create_cum_returns();
		void t_create_pdf_report();
		void t_HTML_display_report();
		void t_test_members();

		// Members
		Performance testing;
		int num_test;

		std::vector<float> t_returns;
		float t_sharpe_ratio;
		float t_drawdowns;
		float t_volatility;
		float t_stddev;
		float t_variance;
		float t_mean;
		std::vector<float> t_cum_returns;

	
};


#endif
