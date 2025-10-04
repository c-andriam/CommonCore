#pragma once
#include <string>
#include <vector>
#include <deque>

int					min(int a, int b);
int					max(int a, int b);
void				display(const std::string& title, std::vector<int> v);
std::vector<int>	mergeInsertSortVector(const std::vector<int>& tokens);
std::deque<int>		mergeInsertSortDeque(const std::deque<int>& tokens);
void				processMerge(int argc, char **argv);
std::vector<int>	splitCommandLineVector(const std::string& line);
std::deque<int>		splitCommandLineDeque(const std::string& line);
