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

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <string>
#include <iostream>

void	polymorphismTest( ClapTrap* robot, const std::string& type )
{
	std::cout << "==== " << type << " polymorphism test ====" << std::endl;
	std::cout << "Robot stats: HitPoints = " << robot->getHitPoints()
		<< "Energy = " << robot->getEnergyPoints()
		<< "Attack = " << robot->getAttackDamage() << std::endl;
	robot->attack("TestTarget");
	std::cout << std::endl;
}

int	main()
{
	std::cout << "==== TEST 1: Polymorphisme ====" << std::endl;
	ClapTrap*	clap = new ClapTrap("TestClap");
	ClapTrap*	scav = new ScavTrap("TestScav");
	ClapTrap*	frag = new FragTrap("TestFrag");

	polymorphismTest(clap, "ClapTrap");
	polymorphismTest(scav, "ScavTrap");
	polymorphismTest(frag, "FragTrap");

	std::cout << std::endl;
	std::cout << "==== TEST 2: FragTrap test ====" << std::endl;
	FragTrap	fraggy("Fraggy");
	for (int i = 0; i <= 5; i++)
	{
		std::cout << "---- Round " << i << " ----" << std::endl;
		fraggy.attack("Enemy");
		fraggy.takeDamage(15);
		fraggy.beRepaired(10);
		fraggy.highFivesGuys();
		std::cout << "HitPoints: " << fraggy.getHitPoints() << " | Energy: " << fraggy.getEnergyPoints() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "==== TEST SIMPLE FragTrap ====" << std::endl;
	FragTrap	fragga("Destroyer");
	std::cout << fragga << std::endl;
	fragga.attack("Enemy");
	fragga.takeDamage(25);
	fragga.beRepaired(15);
	fragga.highFivesGuys();

	std::cout << fragga << std::endl;

	delete clap;
	delete scav;
	delete frag;

	return (0);
}
