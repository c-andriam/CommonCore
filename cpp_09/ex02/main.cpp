#include <iostream>
#include <stdexcept>
#include <vector>
#include <deque>
#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cerr << "Error: missing argument." << std::endl;
		return (-1);
	}
	try
	{
		processMerge(argc, argv);
	}
	catch (std::exception & e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return (0);
}
