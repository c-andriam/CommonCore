/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 08:48:41 by candriam          #+#    #+#             */
/*   Updated: 2025/03/18 09:37:32 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>
#include <iostream>

Zombie::Zombie( std::string name ) : _name(name){}

Zombie::~Zombie( void )
{
	std::cout << this->_name << " destroyed." << std::endl;
}

void	Zombie::announce( void )
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
