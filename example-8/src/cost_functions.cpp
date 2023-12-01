#include <stdexcept>
#include "statistic/cost_functions.hpp"

double statistic::mse(const std::vector<double> &y_actual, const std::vector<double> &y_predicted)
{
	if (y_actual.size() != y_predicted.size())
		throw std::invalid_argument("Input vectors must have the same size");

	std::size_t n = y_actual.size();
	double sum = 0.0;

	for (std::size_t i = 0; i < n; i++) {
		double error = y_actual[i] - y_predicted[i];
		sum += error * error;
	}

	return sum / n;
}

