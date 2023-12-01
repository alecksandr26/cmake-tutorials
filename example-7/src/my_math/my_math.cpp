#include <cmath>

#include "my_math.hpp"

long gcd(long a, long b)
{
	if (a == 0)
		return b;
	return gcd(b % a, a);
}
 
double norm(Vec2D &vec)
{
	return sqrt(vec.x * vec.x + vec.y + vec.y);
}


