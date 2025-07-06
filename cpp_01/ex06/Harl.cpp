/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:49:58 by candriam          #+#    #+#             */
/*   Updated: 2025/03/21 17:15:55 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

Harl::Harl( void )
{
}

Harl::~Harl( void )
{
}

void	Harl::_debug( void )
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my \
7XL-double-cheese-triple-pickle-specialketchup burger." << std::endl << "I really do!"
		<< std::endl << std::endl;
}

void	Harl::_info( void )
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl
		<< "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
		<< std::endl << std::endl;
}

void	Harl::_warning( void )
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl
		<< "I’ve been coming for years, whereas you started working here just last month."
		<< std::endl << std::endl;
}

void	Harl::_error( void )
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now."
		<< std::endl << std::endl;
}

void	Harl::complain( std::string level )
{
	void	(Harl::*ptr[4])() = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	i = -1;
	for (int index = 0; index < 4; index++)
	{
		if (levels[index] == level)
		{
			i = index;
			break ;
		}
	}
	switch (i)
	{
		case 0:
			(this->*ptr[0])();
		case 1:
			(this->*ptr[1])();
		case 2:
			(this->*ptr[2])();
		case 3:
			(this->*ptr[3])();
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break ;
	}
}
