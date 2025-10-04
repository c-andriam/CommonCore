#include <iostream>
#include <stdexcept>
#include "RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: missing argument." << std::endl;
		return (-1);
	}
	try
	{
		RPN	rpn;
		int	result = rpn.computeRPN(argv[1]);
		std::cout << result << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return (0);
}
