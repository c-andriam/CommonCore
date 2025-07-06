/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 13:41:16 by candriam          #+#    #+#             */
/*   Updated: 2025/05/30 10:45:34 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include <iostream>
#include <string>

AAnimal::AAnimal( void ) : type_("AAnimal")
{
	std::cout << "Default AAnimal constructor called." << std::endl;
}

AAnimal::AAnimal( const std::string& type) : type_(type)
{
	std::cout << "AAnimal type '" << getType() << "' has been created." << std::endl;
}

AAnimal::AAnimal( const AAnimal& copy ) : type_(copy.type_)
{
	std::cout << "AAnimal copy constructor called." << std::endl;
}

AAnimal&	AAnimal::operator=( const AAnimal& a )
{
	if (this != &a)
	{
		std::cout << "AAnimal assignment operator called." << std::endl;
		this->type_ = a.type_;
	}
	return (*this);
}

void	AAnimal::setType( const std::string& type )
{
	this->type_ = type;
}

std::string	AAnimal::getType( void ) const
{
	return (this->type_);
}

AAnimal::~AAnimal( void )
{
	std::cout << "AAnimal destructor called." << std::endl;
}
