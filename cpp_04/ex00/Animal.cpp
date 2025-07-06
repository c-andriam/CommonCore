/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 13:41:16 by candriam          #+#    #+#             */
/*   Updated: 2025/05/30 10:45:34 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>
#include <string>

Animal::Animal( void ) : type_("Animal")
{
	std::cout << "Default Animal constructor called." << std::endl;
}

Animal::Animal( const std::string& type) : type_(type)
{
	std::cout << "Animal type '" << getType() << "' has been created." << std::endl;
}

Animal::Animal( const Animal& copy ) : type_(copy.type_)
{
	std::cout << "Animal copy constructor called." << std::endl;
}

Animal&	Animal::operator=( const Animal& a )
{
	if (this != &a)
	{
		std::cout << "Animal assignment operator called." << std::endl;
		this->type_ = a.type_;
	}
	return (*this);
}

void	Animal::setType( const std::string& type )
{
	this->type_ = type;
}

std::string	Animal::getType( void ) const
{
	return (this->type_);
}

void	Animal::makeSound( void ) const
{
	std::cout << "Each animal has its own sound." << std::endl;
}

Animal::~Animal( void )
{
	std::cout << "Animal destructor called." << std::endl;
}
