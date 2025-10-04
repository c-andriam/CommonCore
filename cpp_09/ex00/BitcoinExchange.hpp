#pragma once

#include <string>
#include <map>

class BitcoinExchange
{
	private:
		std::string						_date;
		std::string						_value;
		std::map<std::string, float>	_database;

		bool		isValidDateLength(const std::string& date)  const;
		bool		isValidSeparatorPos(const std::string& date, char sep) const;
		bool		isValidDateSeparator(char sep) const;
		int			stringToInt(std::string date);
		bool		isValidYear(int year) const;
		bool		isValidMonth(int month) const;
		bool		isBisYear(int year) const;
		std::string	purgeSeparator(std::string date);
		std::string	extractYear(std::string date);
		std::string	extractMonth(std::string date);
		std::string	extractDay(std::string date);
		std::string	fullDate(std::string y, std::string m, std::string d);
		bool		isPositiveValue(float value) const;
		bool		isMaxValue(float value) const;
		void		checkRates(const std::string& value);
		bool		isValidRates(float value) const;

	public:
		BitcoinExchange();
		BitcoinExchange(const std::string& date, const std::string& value);
		~BitcoinExchange();

				
		void		createDataBase();
		void		checkValidDate(const std::string& date);
		void		checkValue(const std::string& value);
		void		printOutput(const std::string& date, float value, float result);
		float		computeResult(float value, float exchange_rate);
		float		stringToFloat(const std::string& value);
		float		getRates(const std::string& date) const;
};

std::string			extractDate(const std::string& line);
std::string			extractValue(const std::string& line);
bool				is_header(const std::string& line);
std::string			ftTrim(const std::string& str);
