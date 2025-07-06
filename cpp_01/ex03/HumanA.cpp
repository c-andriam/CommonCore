/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 01:55:19 by candriam          #+#    #+#             */
/*   Updated: 2025/03/19 03:40:13 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanA::HumanA( std::string const& name, Weapon& weapon ) : _name(name), _weapon(weapon)
{
}

HumanA::~HumanA( void )
{
}

void	HumanA::attack( void ) const
{
	std::cout << _name << " attacks with their "
		<< _weapon.getType() << std::endl;
}
