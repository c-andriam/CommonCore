/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 20:55:34 by candriam          #+#    #+#             */
/*   Updated: 2025/03/24 23:38:24 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <ostream>
#include <string>
#include <iostream>

ClapTrap::ClapTrap( void ) : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Default ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap( std::string name ) : _name(name), _hitPoints(10),
	_energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << getName() <<" has been created." << std::endl;
}

ClapTrap::ClapTrap( ClapTrap const& copy ) : _name(copy.getName()),
	_hitPoints(copy.getHitPoints()), _energyPoints(copy.getEnergyPoints()),
	_attackDamage(copy.getAttackDamage())
{
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap&	ClapTrap::operator=( ClapTrap const& copy )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		this->_name = copy.getName();
		this->_hitPoints = copy.getHitPoints();
		this->_energyPoints = copy.getEnergyPoints();
		this->_attackDamage = copy.getAttackDamage();
	}
	return (*this);
}

std::ostream&	operator<<( std::ostream& flux, ClapTrap const& a )
{
	flux << "-----|State|-----" << std::endl << "Name : " << a.getName() << std::endl 
		<< "Hit points: " << a.getHitPoints() << std::endl
		<< "Energy points: " << a.getEnergyPoints() << std::endl
		<< "Attack damage: " << a.getAttackDamage() << std::endl << "-----------------";
	return (flux);
}

void	ClapTrap::attack( const std::string& target )
{
	if (getEnergyPoints() > 0 && getHitPoints() > 0)
	{
		std::cout << "ClapTrap " << getName() << " attacks " << target << ", causing "
			<< getAttackDamage() << " points of damage!" <<std::endl;
		_energyPoints -= 1;
	}
	else
	{
		std::cout << "ClapTrap " << getName() << " can not attack due to insufficient energy" <<
			std::endl;
	}
}

void	ClapTrap::takeDamage( unsigned int amount )
{
	if (amount >= static_cast<unsigned int>(_hitPoints))
		_hitPoints = 0;
	else
		_hitPoints -= static_cast<int>(amount);
	std::cout << "ClapTrap " << getName() << " takes " << amount << " point(s) of damage!"
		<< std::endl;
}

void	ClapTrap::beRepaired( unsigned int amount )
{
	if (getEnergyPoints() > 0 && getHitPoints() > 0)
	{
		_energyPoints -= 1;
		_hitPoints += static_cast<int>(amount);
		std::cout << "ClapTrap " << getName() << " repairs itself, regains " << amount << " hit point(s)!"
			<< std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << getName() << " can not repairs itself, not enough energy or hit points!"
			<< std::endl;
	}
}

std::string	ClapTrap::getName( void ) const
{
	return (this->_name);
}

int	ClapTrap::getHitPoints( void ) const
{
	return (this->_hitPoints);
}

int	ClapTrap::getEnergyPoints( void ) const
{
	return (this->_energyPoints);
}

int	ClapTrap::getAttackDamage( void ) const
{
	return (this->_attackDamage);
}

ClapTrap::~ClapTrap( void )
{
	std::cout << "ClapTrap destructor called" << std::endl;
}
