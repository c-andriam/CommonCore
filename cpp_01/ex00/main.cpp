/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 08:48:00 by candriam          #+#    #+#             */
/*   Updated: 2025/03/18 10:00:53 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie zombie("zomb1");
	zombie.announce();

	Zombie *x = newZombie("zomb2");
	x->announce();

	randomChump("zomb3");

	delete x;	
	return (0);
}
