/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 04:06:35 by candriam          #+#    #+#             */
/*   Updated: 2025/03/25 23:08:51 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "usage: " << argv[0] << " <filename> <to_change> <change_by>."
			<< std::endl;
		return (1);
	}
	std::string	filename = argv[1];
	std::string	first = argv[2];
	std::string	second = argv[3];

	if (argv[2][0] == '\0')
	{
		std::cerr << "error: can not replace this argument '"
			<< argv[2] << "'" << std::endl;
		return (1);
	}
	std::ifstream	inputFile(filename.c_str());
	if (!inputFile.is_open())
	{
		std::cerr << "error: couldn't open file named '" << filename << "'"
			<< std::endl;
		return (1);
	}
	std::stringstream	buffer;
	buffer << inputFile.rdbuf();
	std::string	content = buffer.str();
	inputFile.close();
	std::ofstream	outputFile((filename + ".replace").c_str());
	if (!outputFile.is_open())
	{
		std::cerr << "error: couldn't create file named '" << filename << "'"
			<< ".replace" << std::endl;
		return (1);
	}
	size_t	pos = 0;
	while ((pos = content.find(first, pos)) != std::string::npos)
	{
		content.erase(pos, first.length());
		content.insert(pos, second);
		pos += second.length();
	}
	outputFile << content;
	outputFile.close();
	std::cout << "success: file processed successfuly. Check '" << filename
		<< ".replace" << "'" << std::endl;
	return (0);
}
