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
#include <iostream>
#include <string>

Dog::Dog( void ) : Animal()
{
	std::cout << "Default Dog constructor called." << std::endl;
	this->type_ = "Dog";
}

Dog::Dog( Dog const& copy ) : Animal(copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Dog& Dog::operator=( const Dog& a)
{
	if (this != &a)
	{
		std::cout << "Dog assignment operator called." << std::endl;
		Animal::operator=(a);
		this->type_ = a.type_;
	}
	return (*this);
}

Dog::~Dog( void )
{
	std::cout << "Dog destructor." << std::endl;
}

void	Dog::makeSound( void ) const
{
	std::cout << "Wouf" << std::endl;
}
