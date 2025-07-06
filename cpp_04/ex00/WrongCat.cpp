/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 10:39:04 by candriam          #+#    #+#             */
/*   Updated: 2025/05/30 11:06:33 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#include <iostream>
#include <string>

WrongCat::WrongCat( void ) : WrongAnimal()
{
	std::cout << "Default WrongCat constructor called." << std::endl;
	this->type_ = "WrongCat";
}

WrongCat::WrongCat( WrongCat const& copy ) : WrongAnimal(copy)
{
	std::cout << "Copy constructor called" << std::endl;
	this->type_ = copy.type_;
}

WrongCat& WrongCat::operator=( const WrongCat& a)
{
	if (this != &a)
	{
		std::cout << "WrongCat assignment operator called." << std::endl;
		WrongAnimal::operator=(a);
		this->type_ = a.type_;
	}
	return (*this);
}

WrongCat::~WrongCat( void )
{
	std::cout << "WrongCat destructor." << std::endl;
}

void	WrongCat::makeSound( void ) const
{
	std::cout << "Meouf" << std::endl;
}
