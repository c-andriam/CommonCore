/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 10:41:39 by candriam          #+#    #+#             */
/*   Updated: 2025/05/30 10:47:33 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>
#include <string>

WrongAnimal::WrongAnimal( void ) : type_("WrongAnimal")
{
	std::cout << "Default WrongAnimal constructor called." << std::endl;
}

WrongAnimal::WrongAnimal( const std::string& type) : type_(type)
{
	std::cout << "WrongAnimal type '" << getType() << "' has been created." << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal& copy ) : type_(copy.type_)
{
	std::cout << "WrongAnimal copy constructor called." << std::endl;
}

WrongAnimal&	WrongAnimal::operator=( const WrongAnimal& a )
{
	if (this != &a)
	{
		std::cout << "WrongAnimal assignment operator called." << std::endl;
		this->type_ = a.type_;
	}
	return (*this);
}

void	WrongAnimal::setType( const std::string& type )
{
	this->type_ = type;
}

std::string	WrongAnimal::getType( void ) const
{
	return (this->type_);
}

void	WrongAnimal::makeSound( void ) const
{
	std::cout << "Each wrong animal has its own wrong sound." << std::endl;
}

WrongAnimal::~WrongAnimal( void )
{
	std::cout << "WrongAnimal destructor called." << std::endl;
}
