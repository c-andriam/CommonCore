/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 00:59:07 by candriam          #+#    #+#             */
/*   Updated: 2025/04/05 01:04:31 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap( void ) : ClapTrap("default_clap_name"), ScavTrap(), FragTrap(), _name("default")
{
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << "Default DiamondTrap constructor called" << std::endl;
}

DiamondTrap::DiamondTrap( std::string name ) : ClapTrap(name + "_clap_name"),
	 ScavTrap(name), FragTrap(name), _name(name)
{
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap " << _name <<" has been created." << std::endl;
	std::cout << "Hit points: " << getHitPoints() << std::endl;
	std::cout << "Energy points: " << getEnergyPoints() << std::endl;
	std::cout << "Attack damage: " << getAttackDamage() << std::endl;
}

DiamondTrap::DiamondTrap( DiamondTrap const& copy ) : ClapTrap(copy),
	ScavTrap(copy), FragTrap(copy), _name(copy._name)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap&	DiamondTrap::operator=( DiamondTrap const& copy )
{
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		ClapTrap::operator=(copy);
		_name = copy._name;
	}
	return (*this);
}

void	DiamondTrap::attack( const std::string& target )
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI( void )
{
	std::cout << "I am DiamondTrap called '" << getDiamondName() << "' and my ClapTrap's name is "
		<< ScavTrap::getName() << std::endl;
}

std::string	DiamondTrap::getDiamondName( void ) const
{
	return (_name);
}

DiamondTrap::~DiamondTrap( void )
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}
