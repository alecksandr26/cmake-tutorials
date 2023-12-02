#include <vector>
#include <utility>
#include <stdexcept>
#include <cmath>

#include "statistic/regression.hpp"
#include "statistic/utils.hpp"
#include "statistic/cost_functions.hpp"

statistic::LinearRegressionModel::LinearRegressionModel(void)
{
	b1 = b0 = 0.0;
}

statistic::LinearRegressionModel::~LinearRegressionModel(void)
{
	
}

void statistic::LinearRegressionModel::fit(const std::vector<double> &x,
					   const std::vector<double> &y)
{
	// https://www.oc.nps.edu/oc3140/lab9.htm, for more info of how to fit 
	if (x.size() != y.size())
		throw std::invalid_argument("Input vectors must have the same size");
	
	std::size_t n = x.size();
	
	double mean_x = statistic::mean(x);
	double mean_y = statistic::mean(y);
	double sum_x = statistic::sum(x);
	double sum_y = statistic::sum(y);

	double sum_x_2 = 0.0;
	for (auto num : x)
		sum_x_2 += num * num;
	
	double sum_y_2 = 0.0;
	for (auto num : x)
		sum_y_2 += num * num;

	double sum_x_x = sum_x_2 - (sum_x * sum_x) / n;
	// double sum_y_y = sum_y_2 - (sum_y * sum_y) / n;

	double sum_x_y = 0.0;
	for (std::size_t i = 0; i < n; i++)
		sum_x_y += x[i] * y[i];

	sum_x_y -= sum_x * sum_y / n;

	b1 = sum_x_y / sum_x_x;
	b0 = mean_y - b1 * mean_x;
}

double statistic::LinearRegressionModel::predict(double x)
{
	return x * b1 + b0;
}

double statistic::LinearRegressionModel::score(const std::vector<double> &x,
					       const std::vector<double> &y)
{
	if (x.size() != y.size())
		throw std::invalid_argument("Input vectors must have the same size");

	std::size_t n = x.size();
	std::vector<double> y_predicted(n);

	for (std::size_t i = 0; i < n; i++)
		y_predicted[i] = predict(x[i]);
	
	double sum_y_predicted_2 = 0.0;
	for (std::size_t i = 0; i < n; i++) {
		double error = y[i] - y_predicted[i];
		sum_y_predicted_2 += error * error;
	}

	double mean_y = statistic::mean(y);

	double sum_y_mean_2 = 0.0;
	for (std::size_t i = 0; i < n; i++) {
		double error = y[i] - mean_y;
		sum_y_mean_2 += (error * error);
	}
	
	return 1.0 - (sum_y_predicted_2 / sum_y_mean_2);
}

std::pair<double, double> statistic::LinearRegressionModel::get_coefficients(void)
{
	return std::make_pair(b1, b0);
}

