/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 01:05:12 by candriam          #+#    #+#             */
/*   Updated: 2025/03/19 04:00:19 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <string>

Weapon::Weapon( std::string const& type ) : _type(type)
{
}

Weapon::~Weapon( void )
{
}

void	Weapon::setType( std::string const& type )
{
	this->_type = type;
}

std::string const&	Weapon::getType( void ) const
{
	return (_type);
}
