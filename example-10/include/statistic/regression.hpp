#ifndef REGRESSION_HPP
#define REGRESSION_HPP

#include <vector>
#include <utility>

namespace statistic {
	class LinearRegressionModel {
	private:
		double b0, b1;
		
	public:
		LinearRegressionModel(void);
		~LinearRegressionModel(void);
		
		void fit(const std::vector<double> &x, const std::vector<double> &y);
		double score(const std::vector<double> &x, const std::vector<double> &y);
		double predict(double x);
		
		std::pair<double, double> get_coefficients(void);
	};
}

#endif


