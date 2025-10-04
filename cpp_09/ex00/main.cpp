#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return (-1);
	}
	std::ifstream	file(argv[1]);
	if (!file || !file.is_open())
	{
		std::cerr << "Error: could not read file" << std::endl;
		return (-1);
	}
	BitcoinExchange	btc;
	btc.createDataBase();
	std::string	line;
	if (!std::getline(file, line))
	{
		std::cerr << "Error: file is empty or unreadable" << std::endl;
		return (-1);
	}
	do
	{
		if (!is_header(line))
		{
			std::string	date = extractDate(line);
			std::string	value = extractValue(line);
			try
			{
				btc.checkValidDate(date);
				btc.checkValue(value);
				float	val = btc.stringToFloat(value);
				float	rate = btc.getRates(date);
				float	res = btc.computeResult(val, rate);
				btc.printOutput(date, val, res);
			}
			catch (const std::exception & e)
			{
				std::cerr << "Error: " << e.what() << std::endl;
			}
		}
	}
	while (std::getline(file, line));
	file.close();
	return (0);
}
