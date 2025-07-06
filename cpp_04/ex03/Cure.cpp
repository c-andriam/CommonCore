/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 09:37:11 by candriam          #+#    #+#             */
/*   Updated: 2025/05/31 09:42:54 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure") {}

Cure::Cure( Cure const& copy ) : AMateria(copy) {}

Cure&	Cure::operator=( const Cure& other )
{
	if (this != &other)
	{
		AMateria::operator=(other);
		this->type_ = other.type_;
	}
	return (*this);
}

AMateria*	Cure::clone() const
{
	return (new Cure(*this));
}

void	Cure::use( ICharacter& target )
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

Cure::~Cure() {}
