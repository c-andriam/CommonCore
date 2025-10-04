#pragma once
#include <string>

class RPN
{
	public:
		RPN();
		~RPN();

	int	computeRPN(const std::string& input);
};
