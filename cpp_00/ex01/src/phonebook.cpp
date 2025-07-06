/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:50:14 by candriam          #+#    #+#             */
/*   Updated: 2025/03/18 16:14:05 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PhoneBook.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	PhoneBook phonebook;
	std::string command;
	int exit = 0;

	(void)argv;
	if (argc > 1)
	{
		std::cerr << "error: cannot take arguments" << std::endl;
		return (1);
	}
	do
	{
		std::cout << "Enter a command (ADD or SEARCH or EXIT) : ";
		if (!std::getline(std::cin, command))
			return (1);
		if (command == "ADD")
			phonebook.addContact();
		else if (command == "SEARCH")
		{
			if (phonebook.displayContact() == 1)
				phonebook.searchContact();
			else
				continue ;
		}
		else if (command == "EXIT")
			exit = 1;
		else
		{
			std::cout << "Invalid command."
				<< " Use <ADD> or <SEARCH> or <EXIT>" << std::endl;
		}
	}
	while (!exit);
	return (0);
}
