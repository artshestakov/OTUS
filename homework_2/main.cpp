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

	reader.Sort();
	reader.PrintFull();
	reader.Print1();
	reader.Print4670();
	reader.PrintAny46();

	return 0;
}
//-----------------------------------------------------------------------------
