/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 06:30:03 by candriam          #+#    #+#             */
/*   Updated: 2025/03/21 17:10:48 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <string>

Harl::Harl( void )
{
}

Harl::~Harl( void )
{
}

void	Harl::_debug( void )
{
	std::cout << "[ DEBUG ] : This is just a 'DEBUG' message :)"
		<< std::endl;
}

void	Harl::_info( void )
{
	std::cout << "[ INFO ] : This is an 'INFO' message :)"
		<< std::endl;
}

void	Harl::_warning( void )
{
	std::cout << "[ WARNING ] : Keep calm ! It's just a 'WARNING' :)"
		<< std::endl;
}

void	Harl::_error( void )
{
	std::cout << "[ ERROR ] : Be careful ! An 'ERROR' has occured :- "
		<< std::endl;
}

void	Harl::complain( std::string	level )
{
	void	(Harl::*ptr[4])() = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};

	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int index = 0; index < 4; index++)
	{
		if (levels[index] == level)
		{
			(this->*ptr[index])();
			return ;
		}
	}
	std::cout << "[ FUCK ] : Unknown level :(" << std::endl;
}
