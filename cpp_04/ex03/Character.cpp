/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:53:20 by candriam          #+#    #+#             */
/*   Updated: 2025/05/31 11:10:52 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <cstddef>
#include <iostream>
#include <string>

Character::Character() : _name("default")
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	for (int j = 0; j < 128; j++)
		this->_unequiped[j] = NULL;
}

Character::Character( std::string const& name ) : _name(name)
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	for (int j = 0; j < 128; j++)
		this->_unequiped[j] = NULL;
}

Character::Character( Character const& copy ) : _name(copy._name)
{
	for (int i = 0; i < 4; i++)
	{
		if (copy._inventory[i])
			this->_inventory[i] = copy._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
}

Character&  Character::operator=( Character const& other )
{
	if (this != &other)
	{
		this->_name = other._name;
		for (int i = 0; i < 4; i++)
		{
			if (_inventory[i])
				delete _inventory[i];
			if (other._inventory[i])
				_inventory[i] = other._inventory[i]->clone();
			else
				_inventory[i] = NULL;
		}
	}
	return (*this);
}

std::string const& Character::getName() const
{
	return (this->_name);
}

void	Character::equip( AMateria* m )
{
	if (!m)
	{
		std::cout << "Cannot equip a null materia." << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			return ;
		}
	}
	delete m;
}

void	Character::unequip( int index )
{
	int i;

	if (index < 0 || index >= 4 || this->_inventory[index] == NULL)
		return ;
	for (i = 0; i < 128; ++i)
	{
		if (_unequiped[i] == NULL)
		{
			_unequiped[i] = _inventory[index];
			_inventory[index] = NULL;
			break ;
		}
	}
}

void	Character::use( int index, ICharacter& target )
{
	if (index < 0 || index >= 4 || this->_inventory[index] == NULL)
	{
		std::cout << "Invalid index" << std::endl;
		return ;
	}
	else
	{
		this->_inventory[index]->use(target);
		return ;
	}
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
		{
			delete _inventory[i];
			_inventory[i] = NULL;
		}
	}
}
