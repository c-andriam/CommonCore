/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 19:17:30 by candriam          #+#    #+#             */
/*   Updated: 2025/05/30 10:39:51 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>

Cat::Cat( void ) : Animal()
{
	this->type_ = "Cat";
	this->_brain = new Brain();
	std::cout << "Cat() - Default constructor (brain allocated)" << std::endl;
}

Cat::Cat( Cat const& copy ) : Animal(copy)
{
	this->_brain = new Brain(*copy._brain);
	std::cout << "Cat ( Cat const& ) - Copy constructor (Deep copy of brain)" << std::endl;
}

Cat& Cat::operator=( const Cat& a)
{
	if (this != &a)
	{
		Animal::operator=(a);
		delete this->_brain;
		this->_brain = new Brain (*a._brain);
		std::cout << "Cat assignment operator: old brain deleted, new brain allocated and copied" << std::endl;
	}
	return (*this);
}

void	Cat::makeSound( void ) const
{
	std::cout << "Meow" << std::endl;
}

void	Cat::setBrainIdea( int index, const std::string& idea)
{
	if (this->_brain)
		this->_brain->setIdea(index, idea);
	else
		std::cerr << "Brain not initialized." << std::endl;
}

std::string	Cat::getBrainIdea( int index ) const
{
	if (this->_brain)
		return (this->_brain->getIdea(index));
	std::cerr << "Brain not initialized." << std::endl;
		return ("");
}

Cat::~Cat( void )
{
	delete this->_brain;
	std::cout << "~Cat() - Destructor (Brain deleted)" << std::endl;
}

