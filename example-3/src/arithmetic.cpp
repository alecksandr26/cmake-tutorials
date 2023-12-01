
#include <cmath>
#include "my_math.hpp"

long gcd(long a, long b)
{
	if (b == 0)
		return a;

	return gcd(b, b % a);
}


