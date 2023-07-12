#include <iostream>
#include "version.h"

int main(int, char **)
{
	std::cout << "Build " << VERSION_REVISION << ", " << CONFIGURATION << std::endl;
	std::cout << "Compiled at " << COMPILE_TS_TIME << " on " << COMPILE_TS_DATE << std::endl;
	std::cout << "Hello world!" << std::endl;
	return 0;
}
