// To have output: make test ARGS=-V

#include <iostream>
#include <gtest/gtest.h>
#include <vector>

#include "statistic/utils.hpp"



extern double mean(const std::vector<double> &x);

constexpr double expected_mean = 16.75;
constexpr double tolerance = 1e-6;  // Adjust the tolerance based on your precision requirements

TEST(TestUtils, TrivialMean)
{
	std::vector<double> v = {9.0, 10.0, 12.0, 13.0, 13.0, 13.0, 15.0, 15.0,
				 16.0, 16.0, 18.0, 22.0, 23.0, 24.0, 24.0, 25.0};

	double mean_v = statistic::mean(v);
	EXPECT_NEAR(mean_v, expected_mean, tolerance);
}

TEST(TestUtils, ZeroMean)
{
	std::vector<double> v = {-5.0, -4.0, -3.0, -2.0, -1.0, 1.0, 2.0, 3.0, 4.0, 5.0};

	double mean_v = statistic::mean(v);

	EXPECT_EQ(mean_v, 0.0);
}


