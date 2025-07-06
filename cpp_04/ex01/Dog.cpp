/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 10:18:00 by candriam          #+#    #+#             */
/*   Updated: 2025/05/30 10:41:09 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>

Dog::Dog( void ) : Animal()
{
	this->type_ = "Dog";
	this->_brain = new Brain();
	std::cout << "Dog() - Default constructor (brain allocated)" << std::endl;
}

Dog::Dog( Dog const& copy ) : Animal(copy)
{
	this->_brain = new Brain(*copy._brain);
	std::cout << "Dog ( Dog const& ) - Copy constructor (Deep copy of brain)" << std::endl;
}

Dog& Dog::operator=( const Dog& a)
{
	if (this != &a)
	{
		Animal::operator=(a);
		delete this->_brain;
		this->_brain = new Brain(*a._brain);
		std::cout << "Dog assignment operator: old brain deleted, new brain allocated and copied" << std::endl;
	}
	return (*this);
}

void	Dog::makeSound( void ) const
{
	std::cout << "Wouf" << std::endl;
}

void	Dog::setBrainIdea( int index, const std::string& idea)
{
	if (this->_brain)
		this->_brain->setIdea(index, idea);
	else
		std::cerr << "Brain not initialized." << std::endl;
}

std::string Dog::getBrainIdea( int index ) const
{
	if (this->_brain)
		return (this->_brain->getIdea(index));
	std::cerr << "Brain not initialized." << std::endl;
	return ("");
}

Dog::~Dog( void )
{
	delete this->_brain;
	std::cout << "~Dog() - Destructor (Brain deleted)" << std::endl;
}

