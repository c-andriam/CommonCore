/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 02:13:04 by candriam          #+#    #+#             */
/*   Updated: 2025/03/19 03:51:53 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"
#include <string>
#include <iostream>

HumanB::HumanB( std::string const& name ) : _name(name), _weapon(NULL)
{
}

HumanB::~HumanB( void )
{
}

void	HumanB::attack( void ) const
{
	if (_weapon)
		std::cout << _name << " attacks with their "
			<< _weapon->getType() << std::endl;
	else
		std::cout << _name << " has no weapon to attack with."
			<< std::endl;
}

void	HumanB::setWeapon( Weapon& weapon )
{
	this->_weapon = &weapon;
}
