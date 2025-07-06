/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:03:43 by candriam          #+#    #+#             */
/*   Updated: 2025/03/18 20:22:17 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>
#include <iostream>

Zombie::Zombie( void )
{
	std::cout << "Zombie created." << std::endl;
}

Zombie::~Zombie( void )
{
	std::cout << "Zombie " << getZombieName() << " destroyed." << std::endl;
}

void	Zombie::setZombieName( std::string name )
{
	this->_name = name;
}

std::string	Zombie::getZombieName( void ) const
{
	return (this->_name);
}

void	Zombie::announce( void ) const
{
	std::cout << getZombieName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
