#include "PmergeMe.hpp"
#include <sstream>
#include <string>
#include <stdexcept>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>
#include <iostream>

int	max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

void	display(const std::string& title, std::vector<int> v)
{
	std::cout << title;
	for (size_t i = 0; i < v.size(); ++i)
		std::cout << v[i] << " ";
	std::cout << std::endl;
}

std::vector<int>	mergeInsertSortVector(const std::vector<int>& tokens)
{
	std::vector<int>	large, small, end;
	std::vector<int>	stash = tokens;
	if (stash.size() <= 1)
		return (stash);
	while (stash.size() > 1)
	{
		
		int	a = stash[0];
		int	b = stash[1];
		int	z = max(a, b);
		int	y = min(a, b);
		large.push_back(z);
		small.push_back(y);
		stash.erase(stash.begin() + 1);
		stash.erase(stash.begin());
	}
	if (stash.size() == 1)
	{
		end.push_back(stash.back());
		stash.pop_back();
	}
	std::vector<int>	sorted =  mergeInsertSortVector(large);
	for (size_t i = 0; i < small.size(); ++i)
	{
		int	s = small[i];
		std::vector<int>::iterator it = std::lower_bound(sorted.begin(), sorted.end(), s);
		sorted.insert(it, s);
	}
	for (size_t i = 0; i < end.size(); ++i)
	{
		int	e = end[i];
		std::vector<int>::iterator it = std::lower_bound(sorted.begin(), sorted.end(), e);
		sorted.insert(it, e);
	}
	return (sorted);
}

std::deque<int>	mergeInsertSortDeque(const std::deque<int>& tokens)
{
	std::deque<int>	large, small, end;
	std::deque<int>	stash = tokens;
	if (stash.size() <= 1)
		return (stash);
	while (stash.size() > 1)
	{
		
		int	a = stash[0];
		int	b = stash[1];
		int	z = max(a, b);
		int	y = min(a, b);
		large.push_back(z);
		small.push_back(y);
		stash.erase(stash.begin() + 1);
		stash.erase(stash.begin());
	}
	if (stash.size() == 1)
	{
		end.push_back(stash.back());
		stash.pop_back();
	}
	std::deque<int>	sorted =  mergeInsertSortDeque(large);
	for (size_t i = 0; i < small.size(); ++i)
	{
		int	s = small[i];
		std::deque<int>::iterator it = std::lower_bound(sorted.begin(), sorted.end(), s);
		sorted.insert(it, s);
	}
	for (size_t i = 0; i < end.size(); ++i)
	{
		int	e = end[i];
		std::deque<int>::iterator it = std::lower_bound(sorted.begin(), sorted.end(), e);
		sorted.insert(it, e);
	}
	return (sorted);
}

std::vector<int>	splitCommandLineVector(const std::string& line)
{
	std::istringstream	iss(line);
	std::string			token;
	int					value;
	std::vector<int>	values;
	while (iss >> token)
	{
		if (iss.fail())
			throw std::runtime_error("could not read until the end.");
		std::istringstream	iss1(token);
		iss1 >> value;
		if (iss1.fail() || !iss1.eof())
			throw std::runtime_error("not a valid integer value: '" + token + "'");
		if (token[0] == '-' || value <= 0)
			throw std::runtime_error("not a positive integer value: '" + token + "'");
		values.push_back(value);
	}
	return (values);
}

std::deque<int>	splitCommandLineDeque(const std::string& line)
{
	std::istringstream	iss(line);
	std::string			token;
	int					value;
	std::deque<int>		values;
	while (iss >> token)
	{
		if (iss.fail())
			throw std::runtime_error("could not read until the end.");
		std::istringstream	iss1(token);
		iss1 >> value;
		if (iss1.fail() || !iss1.eof())
			throw std::runtime_error("not a valid integer value: '" + token + "'");
		if (token[0] == '-' || value <= 0)
			throw std::runtime_error("not a positive integer value: '" + token + "'");
		values.push_back(value);
	}
	return (values);
}

void	processMerge(int argc, char **argv)
{
	std::vector<int>vector_tokens, vector_value;
	std::deque<int>	deque_tokens, deque_value;
	for (int i = 1; i < argc; ++i)
	{
		vector_value = splitCommandLineVector(argv[i]);
		deque_value = splitCommandLineDeque(argv[i]);
		vector_tokens.insert(vector_tokens.end(), vector_value.begin(), vector_value.end());
		deque_tokens.insert(deque_tokens.end(), deque_value.begin(), deque_value.end());
	}
	display("Before: ", vector_tokens);
	std::clock_t	start = std::clock();
	std::vector<int>	sorted = mergeInsertSortVector(vector_tokens);
	std::clock_t	end = std::clock();
	double	duration = static_cast<double>(end - start) * 1e6 / CLOCKS_PER_SEC;
	display("After:  ", sorted);
	std::cout << "Time to process a range of " << vector_tokens.size() << " elements with std::vector : " << duration << " us" << std::endl;
	std::clock_t	start1 = std::clock();
	std::deque<int>	sorted1 = mergeInsertSortDeque(deque_tokens);
	std::clock_t	end1 = std::clock();
	double	duration1 = static_cast<double>(end1 - start1) * 1e6 / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << deque_tokens.size() << " elements with std::deque : " << duration1 << " us" << std::endl;
}
