#include "BitcoinExchange.hpp"
#include <string>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <map>
#include <fstream>
#include <algorithm>

BitcoinExchange::BitcoinExchange() : _date(""), _value("")
{
}

BitcoinExchange::BitcoinExchange( const std::string& date, const std::string& value ) : _date(date), _value(value)
{
}

BitcoinExchange::~BitcoinExchange()
{
}

void	BitcoinExchange::createDataBase()
{
	try
	{
		std::ifstream	file("../data.csv");
		if (!file || !file.is_open())
			throw std::runtime_error("could not read file");
		std::string	line;
		if (!std::getline(file, line))
			throw std::runtime_error("file is empty or unreadable");
		do
		{
			if (!is_header(line))
			{
				std::string	date = extractDate(line);
				std::string	rate = extractValue(line);
				BitcoinExchange	btc(date, rate);
				try
				{
					btc.checkValidDate(date);
					btc.checkRates(rate);
					float	flt_rate = btc.stringToFloat(rate);
					_database.insert(std::make_pair(date, flt_rate));
				}
				catch (const std::exception & e)
				{
					std::cerr << "Error: " << e.what() << std::endl;
				}
			}
		}
		while (std::getline(file, line));
		file.close();
	}
	catch (const std::exception & e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

float	BitcoinExchange::getRates(const std::string& date) const
{
	std::map<std::string, float>::const_iterator	it = _database.lower_bound(date);
	if (it == _database.end())
	{
		if (_database.empty())
			throw std::runtime_error("database is empty");
		--it;
	}
	else if (it->first != date)
	{
		if (it == _database.begin())
			throw std::runtime_error("date too old no rates available");
		--it;
	}
	return (it->second);
}

bool	is_header(const std::string& line)
{
	return ((line.find("date") != std::string::npos && line.find("value") != std::string::npos)
			|| (line.find("date") != std::string::npos && line.find("exchange_rate")));
}

void	BitcoinExchange::printOutput(const std::string& date, float value, float result)
{
	std::cout << date << " => ";
	std::cout << value << " = ";
	std::cout << result << std::endl;
}

std::string	extractDate(const std::string& line)
{
	std::string	date;
	std::size_t	pos = line.find("|");
	if (pos != std::string::npos)
	{
		date = line.substr(0, pos - 1);
		return (date);
	}
	pos = line.find(",");
	if (pos != std::string::npos)
	{
		date = line.substr(0, pos);
		return (date);
	}
	return (line);
}

std::string	extractValue(const std::string& line)
{
	std::string	value;
	std::size_t	pos = line.find("|");
	if (pos != std::string::npos)
	{
		value = line.substr(pos + 2);
		return (value);
	}
	pos = line.find(",");
	if (pos != std::string::npos)
	{
		value = line.substr(pos + 1);
		return (value);
	}
	return ("");
}

float	BitcoinExchange::computeResult(float value, float exchange_rate)
{
	float	final_value = value * exchange_rate;
	return (final_value);
}

void	BitcoinExchange::checkValidDate(const std::string& date)
{
	std::string	full_date = purgeSeparator(date);
	std::string	year = extractYear(full_date);
	std::string	month = extractMonth(full_date);
	std::string	day = extractDay(full_date);
	std::string	joined = fullDate(year, month, day);
	std::string	msg = "bad input => " + joined;
	if (!isValidDateLength(date) || !isValidDateSeparator(date[4]) || !isValidDateSeparator(date[7]) || !isValidSeparatorPos(date, date[4]))
		throw std::runtime_error(msg);
	int	int_year = stringToInt(year);
	int	int_month = stringToInt(month);
	int	int_day = stringToInt(day);
	if (!isValidYear(int_year))
		throw std::runtime_error(msg);
	if (int_month < 1 || int_month > 12)
		throw std::runtime_error(msg);
	int	last_day = 31;
	if (int_month == 2)
	{
		last_day = (isBisYear(int_year) ? 29 : 28);
		if (int_day < 1 || int_day > last_day)
			throw std::runtime_error(msg);
	}
	else if (int_month == 4 || int_month == 6 || int_month == 9 || int_month == 11)
	{
		last_day = 30;
		if (int_day < 1 || int_day > last_day)
			throw std::runtime_error(msg);
	}
	else
	{
		if (int_day < 1 || int_day > last_day)
			throw std::runtime_error(msg);
	}
}

bool	BitcoinExchange::isValidDateLength(const std::string& date) const
{
	return (date.size() == 10);
}

bool	BitcoinExchange::isValidSeparatorPos(const std::string& date, char sep) const
{
	return (date[4] == sep && date[7] == sep);
}

bool	BitcoinExchange::isValidDateSeparator(char sep) const
{
	return (sep == '-');
}

int	BitcoinExchange::stringToInt(std::string date)
{
	std::istringstream	iss(date);
	int	ui_date;
	iss >> ui_date;
	return (ui_date);
}

bool	BitcoinExchange::isValidYear(int year) const
{
	return (year >= 2009);
}

bool	BitcoinExchange::isValidMonth(int month) const
{
	return (month >= 1 && month <= 12);
}

bool	BitcoinExchange::isBisYear(int year) const
{
	return ((year % 4) == 0 && (year % 100 != 0 || year % 400 == 0));
}

std::string	BitcoinExchange::purgeSeparator(std::string date)
{
	std::string	str_year = date.substr(0, 4);
	std::string	str_month = date.substr(5, 2);
	std::string	str_day = date.substr(8, 2);
	std::string	str_date = str_year + str_month + str_day;
	return (str_date);
}

std::string	BitcoinExchange::extractYear(std::string date)
{
	std::string	year = date.substr(0, 4);
	return (year);
}

std::string	BitcoinExchange::extractMonth(std::string date)
{
	std::string	month = date.substr(4, 2);
	return (month);
}

std::string	BitcoinExchange::extractDay(std::string date)
{
	std::string	day = date.substr(6, 2);
	return (day);
}

std::string	BitcoinExchange::fullDate(std::string y, std::string m, std::string d)
{
	std::string	date = y + "-" + m + "-" + d;
	return (date);
}

void	BitcoinExchange::checkValue(const std::string& value)
{
	if (!isPositiveValue(stringToFloat(value)))
		throw std::runtime_error("not a positive number.");
	if (isMaxValue(stringToFloat(value)))
		throw std::runtime_error("too large a number.");
}

void	BitcoinExchange::checkRates(const std::string& value)
{
	if (!isValidRates(stringToFloat(value)))
		throw std::runtime_error("not a positive number.");
}

bool	BitcoinExchange::isValidRates(float value) const
{
	return (value >= 0.0);
}

bool	BitcoinExchange::isPositiveValue(float value) const
{
	return (value > 0.0);
}

bool	BitcoinExchange::isMaxValue(float value) const
{
	return (value >= 1000.0);
}

float	BitcoinExchange::stringToFloat(const std::string& value)
{
	std::istringstream	iss(value);
	float	flt_value;
	iss >> flt_value;
	return (flt_value);
}
