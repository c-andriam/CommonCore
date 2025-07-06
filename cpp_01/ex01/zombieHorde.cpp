/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:04:59 by candriam          #+#    #+#             */
/*   Updated: 2025/03/18 20:24:22 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>

Zombie*	zombieHorde( int N, std::string name )
{
	if (N <= 0)
		return (NULL);
	Zombie*	zombie = new Zombie[N];
	for (int index = 0; index < N; index++)
	{
		zombie[index].setZombieName( name );
	}
	return (zombie);
}
