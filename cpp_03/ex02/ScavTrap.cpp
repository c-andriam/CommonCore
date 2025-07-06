/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:57:05 by candriam          #+#    #+#             */
/*   Updated: 2025/03/25 15:49:58 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap( void ) : ClapTrap()
{
	_hitPoints =100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "Default ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap( name )
{
	_hitPoints =100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap " << getName() <<" has been created." << std::endl;
}

ScavTrap::ScavTrap( ScavTrap const& copy ) : ClapTrap( copy )
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap&	ScavTrap::operator=( const ScavTrap& copy )
{
	std::cout << "ScavTrap copy assignement operator called" << std::endl;
	if (this != &copy)
		ClapTrap::operator=(copy);
	return (*this);
}

void	ScavTrap::attack( const std::string& target )
{
	if (getEnergyPoints() > 0 && getHitPoints() > 0)
	{
		std::cout << "ScavTrap " << getName() << " attacks '" << target << "', causing "
			<< getAttackDamage() << " points of damage!" <<std::endl;
		_energyPoints -= 1;
	}
	else
	{
		std::cout << "ScavTrap " << getName() << " can not attack due to insufficient energy" <<
			std::endl;
	}
}

void	ScavTrap::guardGate( void ) const
{
	std::cout << "ScavTrap '" << getName() << "' is now in Gate keeper mode, no damage is applied" << std::endl;
}

ScavTrap::~ScavTrap( void )
{
	std::cout << "ScavTrap destructor called" << std::endl;
}
