#include <iostream>
#include "version.h"

int main(int, char **)
{
	std::cout << "Build, " << PROJECT_VERSION_PATCH << std::endl;
	std::cout << "Hello world!" << std::endl;
	return 0;
}
