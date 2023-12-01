#include <vector>

#include "statistic/utils.hpp"

double statistic::mean(const std::vector<double> &x)
{
	return sum(x) / x.size();
}

double statistic::sum(const std::vector<double> &x)
{
	double sum_ = 0.0;
	for (auto num : x)
		sum_ += num;
	
	return sum_;
}



