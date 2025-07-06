/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:14:58 by candriam          #+#    #+#             */
/*   Updated: 2025/03/18 20:24:00 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <cstddef>
#include <string>

int	main()
{
	int	N(4);
	std::string	name("Foo");
	Zombie*	zombie = zombieHorde(N, name );
	if (zombie != NULL)
	{
		for (int index(0); index < N; index++)
			zombie[index].announce();
		delete []zombie;
	}
	return (0);
}
