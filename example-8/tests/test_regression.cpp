#include <iostream>
#include <gtest/gtest.h>
#include <vector>
#include <utility>

#include "statistic/regression.hpp"

static constexpr double score_expected = 0.71;
static constexpr double b0_expected = 5.63;
static constexpr double b1_expected = 0.54;
static constexpr double tolerance = 1e-2;

TEST(LinearRegressionTest, TrivialRegression) {
	statistic::LinearRegressionModel model;


	std::vector<double> x = {5.0, 15.0, 25.0, 35.0, 45.0, 55.0};
	std::vector<double> y = {5.0, 20.0, 14.0, 32.0, 22.0, 38.0};

	model.fit(x, y);
	
	std::cout << model.get_coefficients().first <<
		" " << model.get_coefficients().second << std::endl;

	EXPECT_NEAR(model.get_coefficients().first, b1_expected, tolerance);
	EXPECT_NEAR(model.get_coefficients().second, b0_expected, tolerance);
	
	std::cout << model.score(x, y) << std::endl;

	EXPECT_NEAR(model.score(x, y), score_expected, tolerance);
}

