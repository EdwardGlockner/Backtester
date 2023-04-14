/*

*/
#ifndef T_DATA_H
#define T_DATA_H

#include <iostream>

#include "../src/Data/data.h"

class t_data {
	public:
		// Constructors
		t_data();
		~t_data();

		// Methods
		void t_open_convert_csv_file();
		void t_get_new_bar();
		void t_get_latest_bars();
		void t_update_bars();
		void t_testing_members();

		// Members
		HistoricCSVDataHandler testing;
		int num_test;

};


#endif
