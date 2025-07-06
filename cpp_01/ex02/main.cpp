/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 23:19:41 by candriam          #+#    #+#             */
/*   Updated: 2025/03/19 00:33:03 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main()
{
	std::string		brain = "HI THIS IS BRAIN";
	std::string*	stringPTR = &brain;
	std::string&	stringREF = brain;

	std::cout << "--------------------|Memory  Addresses|--------------------"
		<< std::endl;
	std::cout << std::endl << "• The memory address of the string variable: "
		<< &brain << std::endl;
	std::cout << "• The memory address held by stringPTR: "
		<< stringPTR << std::endl;
	std::cout << "• The memory address held by stringREF: "
		<< &stringREF << std::endl;
	std::cout << std::endl << "-----------------------------------------------------------"
		<< std::endl;
	std::cout << std::endl << "-------------------|String  Value|-------------------"
		<< std::endl;
	std::cout << std::endl << "• The value of the string variable: "
		<< brain << std::endl;
	std::cout << "• The value pointed to by stringPTR: "
		<< *stringPTR << std::endl;
	std::cout << "• The value pointed to by stringREF: "
		<< stringREF << std::endl;
	std::cout << std::endl << "-----------------------------------------------------"
		<< std::endl;
	return (0);
}
