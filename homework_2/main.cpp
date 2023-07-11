#include <iostream>
#include "IPReader.h"
//-----------------------------------------------------------------------------
int main(/*int argc, char **argv*/)
{
	IPReader reader("C:\\Shara\\ip_filter.csv");
	if (!reader.Parse())
	{
		std::cout << reader.GetErrorString() << std::endl;
		return 1;
	}

	return 0;
}
//-----------------------------------------------------------------------------
