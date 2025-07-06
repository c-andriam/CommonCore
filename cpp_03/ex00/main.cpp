/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 21:03:42 by candriam          #+#    #+#             */
/*   Updated: 2025/03/25 14:45:33 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <string>
#include <iostream>

int	main()
{
	std::cout << "==== TEST 1: Constructeurs ====" << std::endl;

	ClapTrap	defaultClapTrap;
	std::cout << defaultClapTrap << std::endl << std::endl;

	ClapTrap	clap("Clappy");
	std::cout << clap << std::endl << std::endl;

	ClapTrap	copyClapTrap(clap);
	std::cout << copyClapTrap << std::endl << std::endl;

	ClapTrap	assignClapTrap;
	assignClapTrap = clap;
	std::cout << assignClapTrap << std::endl << std::endl;

	std::cout << "==== TEST 2: Attaques ====" << std::endl;

	ClapTrap	clappy("ClappyAttack");
	std::cout << clappy << std::endl;

	int	i = 0;
	while (i < 5)
	{
		clappy.attack("Target");
		std::cout << "Energy: " << clappy.getEnergyPoints() << std::endl;
		i++;
	}
	std::cout << std::endl;

	std::cout << "==== TEST 3: Degats ====" << std::endl;

	ClapTrap	clappo("Victim");
	std::cout << clappo << std::endl;

	clappo.takeDamage(5);
	std::cout << "HitPoints after 5 damage: " << clappo.getHitPoints() << std::endl;

	clappo.takeDamage(22);
	std::cout << "HitPoints after 22 damage: " << clappo.getHitPoints() << std::endl;
	std::cout << std::endl;
	
	std::cout << "==== TEST 4: Reparations ====" << std::endl;

	ClapTrap	clappe("Clappe");
	std::cout << clappe << std::endl;

	clappe.takeDamage(7);
	std::cout << "HitPoints after 7 damage: " << clappe.getHitPoints() << std::endl;
	
	clappe.beRepaired(5);
	std::cout << "HitPoints after repair: " << clappe.getHitPoints() << std::endl;

	clappe.beRepaired(50);
	std::cout << "HitPoints after big repair: " << clappe.getHitPoints() << std::endl;
	std::cout << std::endl;

	std::cout << "==== TEST 5: Epuisement d'energie ====" << std::endl;

	ClapTrap	clappa("Tired");

	for (int i = 0; i < 15; i++)
	{
		std::cout << "Action " << (i + 1) << ": ";
		if (i % 2 == 0)
			clappa.attack("Enemy");
		else
			clappa.beRepaired(1);
		std::cout << "Energie: " << clappa.getEnergyPoints() << std::endl;
	}
	std::cout << std::endl;


	std::cout << "==== TEST 6: Mort ====" << std::endl;

	ClapTrap	deadClap("Clapp");
	deadClap.takeDamage(17);
	std::cout << "HitPoints: " << deadClap.getHitPoints() << std::endl;

	deadClap.attack("Target");
	deadClap.beRepaired(5);
	std::cout << std::endl;

	std::cout << "==== TEST 7: Operateur de flux ====" << std::endl;

	ClapTrap	displayClap("ClapTrap");
	displayClap.takeDamage(2);
	displayClap.attack("Enemy");
	std::cout << displayClap << std::endl;

	
	std::cout << "==== FIN DES TESTS ====" << std::endl;


	return (0);
}
