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
#include <iostream>

Cat::Cat( void ) : Animal()
{
	std::cout << "Default Cat constructor called." << std::endl;
	this->type_ = "Cat";
}

Cat::Cat( Cat const& copy ) : Animal(copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Cat& Cat::operator=( const Cat& a)
{
	if (this != &a)
	{
		std::cout << "Cat assignment operator called." << std::endl;
		Animal::operator=(a);
		this->type_ = a.type_;
	}
	return (*this);
}

Cat::~Cat( void )
{
	std::cout << "Cat destructor." << std::endl;
}

void	Cat::makeSound( void ) const
{
	std::cout << "Meow" << std::endl;
}
