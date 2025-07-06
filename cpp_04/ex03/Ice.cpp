/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 09:23:25 by candriam          #+#    #+#             */
/*   Updated: 2025/05/31 09:43:06 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice") {}

Ice::Ice( Ice const& copy ) : AMateria(copy) {}

Ice&	Ice::operator=( Ice const& other )
{
	if (this != &other)
	{
		AMateria::operator=(other);
		this->type_ = other.type_;
	}
	return (*this);
}

AMateria*	Ice::clone() const
{
	return (new Ice(*this));
}

void	Ice::use( ICharacter& target )
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

Ice::~Ice() {}
