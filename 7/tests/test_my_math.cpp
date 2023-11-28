
#include <iostream>
#include <gtest/gtest.h>

#include "my_math.hpp"

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
	// Expect two strings not to be equal.
	EXPECT_STRNE("hello", "world");
	// Expect equality.
	EXPECT_EQ(7 * 6, 42);
}

TEST(GcdTest, simpleTest) {
	EXPECT_EQ(gcd(9, 3), 3);
}



