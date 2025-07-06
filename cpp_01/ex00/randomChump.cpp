/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 09:54:20 by candriam          #+#    #+#             */
/*   Updated: 2025/03/18 10:03:19 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>

void	randomChump( std::string name )
{
	Zombie*	myFirstZombie = newZombie( name );
	myFirstZombie->announce();
	delete myFirstZombie;
}
