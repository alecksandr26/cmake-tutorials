#ifndef VEC_HPP
#define VEC_HPP
#include <cmath>

struct V2d {
	double x, y;
};

double norm(V2d &v2d)
{
	return sqrt(v2d.x * v2d.x + v2d.y * v2d.y);
}

#endif

