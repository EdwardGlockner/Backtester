#ifndef PERFORMANCE
#define PERFORMANCE

#include <vector>

class Performance {
	public:
		Performance(const std::vector<float>& in_returns);
		~Performance();

		float create_sharpe_ratio(int periods = 252);
		float create_drawdowns();
		float create_volatility(int periods = 252);
		float create_stddev();
		float create_variance();
		std::vector<float> create_cum_returns();
		void create_pdf_report();
		void HTML_display_report();
		
		std::vector<float> returns;
		float sharpe_ratio;
		float drawdowns;
		float volatility;
		float stddev;
		float variance;
		std::vector<float> cum_returns;

	private:
		float calc_mean();


};


#endif
