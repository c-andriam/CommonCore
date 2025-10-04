#include "RPN.hpp"
#include <stack>
#include <string>
#include <stdexcept>
#include <sstream>

RPN::RPN()
{
}

RPN::~RPN()
{
}

int	RPN::computeRPN(const std::string& input)
{
	std::stack<int>	stk;
	std::istringstream	iss(input);
	std::string	token;

	while (iss >> token)
	{
		if (token.size() == 1 && std::isdigit(token[0]))
		{
			int	value = token[0] - '0';
			stk.push(value);
		}
		else if (token.size() == 1 && (token == "-" || token == "+" || token == "*" || token == "/"))
		{
			if (stk.size() < 2)
				throw std::runtime_error("not enough size to operate RPN");
			int	b = stk.top();
			stk.pop();
			int	a = stk.top();
			stk.pop();
			int	result;
			if (token == "-")
				result = a - b;
			else if (token == "+")
				result = a + b;
			else if (token == "*")
				result = a * b;
			else if (token == "/")
			{
				if (b == 0)
					throw std::runtime_error("could not divide number by 0");
				else
					result = a / b;
			}
			stk.push(result);
		}
		else
			throw std::runtime_error("invalid token near > '" + token + "'");
	}
	if (stk.size() != 1)
		throw std::runtime_error("invalid RPN expression");
	return (stk.top());
}
