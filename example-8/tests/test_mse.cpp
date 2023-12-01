// To have output: make test ARGS=-V

#include <iostream>
#include <gtest/gtest.h>

#include "statistic/cost_functions.hpp"

static constexpr double mse_expected = 0.1975;

TEST(MseTest, TrivialMse) {
	std::vector<double> actual = {1.0, 2.0, 3.0, 4.0};
	std::vector<double> predicted = {1.5, 2.5, 2.8, 3.5};
	
	double mse = statistic::mse(actual, predicted);
	

	std::cout << "Mse: " << mse << std::endl;
	
	EXPECT_EQ(mse, mse_expected);
}



TEST(MseTest, MseZero) {
	std::vector<double> actual = {1.5, 2.5, 2.8, 3.5};
	std::vector<double> predicted = {1.5, 2.5, 2.8, 3.5};
	
	double mse = statistic::mse(actual, predicted);
	
	std::cout << "Mse: " << mse << std::endl;
	
	EXPECT_EQ(mse, 0.0);
}

