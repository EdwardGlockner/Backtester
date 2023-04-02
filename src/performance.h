#ifndef PERFORMANCE
#define PERFORMANCE

#include <vector>

class Performance {
	public:
		Performance(const std::vector<float>& in_returns);
		~Performance();

		float create_sharpe_ratio();
		float create_drawdowns();
		float create_volatility();
		void create_pdf_report();
		void HTML_display_report();
		
		std::vector<float> returns;
		float sharpe_ratio;
		float drawdowns;
		float volatility;

	private:


};


#endif
