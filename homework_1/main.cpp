#include <iostream>
#include "version.h"

int main(int, char **)
{
	std::cout << "Build " << VERSION_REVISION << std::endl;
	std::cout << "Hello world!" << std::endl;
	return 0;
}
