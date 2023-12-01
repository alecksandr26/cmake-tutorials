
// To compile the shared library
// `c++ test_install.cpp -lstatistic -Wl,-R/usr/local/lib`
// -Wl,-R/usr/local/lib: Passes the -R/usr/local/lib option to the linker,
// instructing it to add /usr/local/lib to the runtime library search path.

#include <iostream>
#include <vector>
#include <statistic/regression.hpp>


int main(void)
{
	statistic::LinearRegressionModel model;


	std::vector<double> x = {5.0, 15.0, 25.0, 35.0, 45.0, 55.0};
	std::vector<double> y = {5.0, 20.0, 14.0, 32.0, 22.0, 38.0};

	model.fit(x, y);
	
	std::cout << model.get_coefficients().first <<
		" " << model.get_coefficients().second << std::endl;
	std::cout << model.score(x, y) << std::endl;
	
	return 0;
}
