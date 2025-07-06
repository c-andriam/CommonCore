/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:16:25 by candriam          #+#    #+#             */
/*   Updated: 2025/05/31 11:08:49 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>
#include <string>

AMateria::AMateria() : type_("default")
{
}

AMateria::AMateria( std::string const& type ) : type_(type)
{
}

AMateria::AMateria( AMateria const& copy ) : type_(copy.type_)
{
}

AMateria& AMateria::operator=( AMateria const& a )
{
	if (this != &a)
	{
		this->type_ = a.type_;
	}
	return (*this);
}

std::string const& AMateria::getType() const
{
	return (this->type_);
}

void AMateria::use( ICharacter& target )
{
	std::cout << "* uses " << getType() << " on " << target.getName() << " *" << std::endl;
}

AMateria::~AMateria()
{
}
