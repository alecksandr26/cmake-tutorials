#include <iostream>

// This could return an error, but with cmake is possible
#include "vec.hpp"

int main(void)
{
	V2d v2d = {
		10.2,
		21.5
	};

	std::cout << norm(v2d) << std::endl;
	
	return 0;
}
