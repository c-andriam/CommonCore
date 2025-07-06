/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 00:56:22 by candriam          #+#    #+#             */
/*   Updated: 2025/03/26 01:16:46 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>
#include <string>

FragTrap::FragTrap( void ) : ClapTrap()
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "Default FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap( std::string name ) : ClapTrap( name )
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << getName() <<" has been created." << std::endl;
}

FragTrap::FragTrap( FragTrap const& copy ) : ClapTrap( copy )
{
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap&	FragTrap::operator=( FragTrap const& a )
{
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	if (this != &a)
		ClapTrap::operator=(a);
	return (*this);
}

void	FragTrap::attack( const std::string& target )
{
	if (getEnergyPoints() > 0 && getHitPoints() > 0)
	{
		std::cout << "FragTrap " << getName() << " launches a devastating attack on " << target << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
		_energyPoints -= 1;
	}
	else
	{
		std::cout << "FragTrap " << getName() << " can not attack due to insufficient energy or hit points" << std::endl;
	}
}

void	FragTrap::highFivesGuys( void ) const
{
	std::cout << "FragTrap " << getName() << ": Let's spread some positivity ✋High five everyone" << std::endl;
}

FragTrap::~FragTrap( void )
{
	std::cout << "FragTrap destructor called" << std::endl;
}
