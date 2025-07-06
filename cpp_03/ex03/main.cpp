/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 21:03:42 by candriam          #+#    #+#             */
/*   Updated: 2025/03/26 01:21:48 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>
#include <sstream>

std::string	toString( int value )
{
	std::stringstream	ss;
	ss << value;
	return (ss.str());
}

int	main()
{
	std::cout << "==== DIAMONDTRAP TEST ====" << std::endl << std::endl;
	std::cout << "1. Construction:" << std::endl;
	DiamondTrap	diamond("Diamond");
	std::cout << "HitPoints: " << diamond.getHitPoints() << " | Energy: " << diamond.getEnergyPoints()
		<< " | Attack: " << diamond.getAttackDamage() << std::endl;
	std::cout << std::endl << "2. Identity:" << std::endl;
	diamond.whoAmI();
	std::cout << std::endl << "3. Inherited functions:" << std::endl;
	diamond.attack("Target");
	diamond.guardGate();
	diamond.highFivesGuys();
	diamond.takeDamage(25);
	diamond.beRepaired(10);
	std::cout << std::endl << "4. Combat test:" << std::endl;
	for (int i = 1; i <= 3; i++)
	{
		diamond.attack("Enemy" + toString(i));
		std::cout << "Energy: " << diamond.getEnergyPoints() << std::endl;
	}
	std::cout << std::endl << "5. Polymorphism:" << std::endl;
	ClapTrap*	polyClap = new DiamondTrap("PolyDiamond");
	polyClap->attack("PolyTarget");

	std::cout << std::endl << "6. Copy operations:" << std::endl;
	DiamondTrap	copy(diamond);
	copy.whoAmI();

	DiamondTrap	assign;
	assign = diamond;
	assign.whoAmI();

	std::cout << std::endl << "7. Limits:" << std::endl;
	diamond.takeDamage(200);
	diamond.attack("Victim");
	diamond.whoAmI();

	delete polyClap;
	std::cout << std::endl << "==== TEST COMPLETE ====" << std::endl;
	return (0);
}
