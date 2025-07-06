/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 09:27:56 by candriam          #+#    #+#             */
/*   Updated: 2025/03/18 19:53:56 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>

Zombie*	newZombie( std::string name )
{
	Zombie*	zombie = new Zombie( name );
	return (zombie);
}
