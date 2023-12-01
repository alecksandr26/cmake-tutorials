#ifndef COST_FUNCTIONS_HPP
#define COST_FUNCTIONS_HPP

#include <vector>

namespace statistic {
	extern double mse(const std::vector<double> &y_actual, const std::vector<double> &y_predicted);
}

#endif

