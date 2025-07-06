/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 21:03:42 by candriam          #+#    #+#             */
/*   Updated: 2025/03/25 15:47:46 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <string>
#include <iostream>

int	main()
{
	std::cout << "==== TEST 1: Constructeurs ScavTrap ====" << std::endl;

	ScavTrap	defaultScavTrap;
	std::cout << defaultScavTrap << std::endl << std::endl;

	ScavTrap	scav("Scavy");
	std::cout << scav << std::endl << std::endl;

	ScavTrap	copyScavTrap(scav);
	std::cout << copyScavTrap << std::endl << std::endl;

	ScavTrap	assignScavTrap;
	assignScavTrap = scav;
	std::cout << assignScavTrap << std::endl << std::endl;

	std::cout << "==== TEST 2: Comparaison ClapTrap vs ScavTrap ====" << std::endl;

	ClapTrap	clappy("Clappy");
	ScavTrap	scavy("Scavy");

	std::cout << "ClapTrap stats: " << clappy << std::endl;
	std::cout << "ScavTrap stats: " << scavy << std::endl;

	std::cout << "==== TEST 3: Attaques ScavTrap ====" << std::endl;

	ScavTrap	soldier("ScavSoldier");
	std::cout << "Init state: " << std::endl << soldier << std::endl;

	int	i = 0;
	while (i < 5)
	{
		soldier.attack("Target");
		std::cout << "Energy after attack: " << soldier.getEnergyPoints() << std::endl;
		i++;
	}
	std::cout << std::endl;

	std::cout << "==== TEST 4: Fonction guardGate ====" << std::endl;

	ScavTrap	scavGuard("Guard");
	scavGuard.guardGate();

	scavGuard.takeDamage(30);
	std::cout << "HitPoints after 30 damage: " << scavGuard.getHitPoints() << std::endl;

	scavGuard.guardGate();
	std::cout << std::endl;
	
	std::cout << "==== TEST 5: Resistance ScavTrap ====" << std::endl;

	ScavTrap	resistScav("ResistScav");
	std::cout << "Init HitPoints: " << resistScav.getHitPoints() << std::endl;

	resistScav.takeDamage(50);
	std::cout << "HitPoints after 50 damage: " << resistScav.getHitPoints() << std::endl;
	
	resistScav.takeDamage(30);
	std::cout << "HitPoints after 30 damage: " << resistScav.getHitPoints() << std::endl;
	
	resistScav.takeDamage(25);
	std::cout << "HitPoints after 25 damage: " << resistScav.getHitPoints() << std::endl;
	std::cout << std::endl;

	std::cout << "==== TEST 6: Reparation ScavTrap ====" << std::endl;

	ScavTrap	repScav("Scavio");
	repScav.takeDamage(40);
	std::cout << "HitPoints after 40 damage: " << repScav.getHitPoints() << std::endl;

	repScav.beRepaired(20);
	std::cout << "HitPoints after repair: " << repScav.getHitPoints() << std::endl;
	std::cout << "Energie after repair: " << repScav.getEnergyPoints() << std::endl;
	
	repScav.beRepaired(50);
	std::cout << "HitPoints after big repair: " << repScav.getHitPoints() << std::endl;
	std::cout << "Energie after repair: " << repScav.getEnergyPoints() << std::endl;
	std::cout << std::endl;

	std::cout << "==== TEST 7: Epuisement d'Energie ScavTrap ====" << std::endl;

	ScavTrap	scave("ScavEnergy");
	std::cout << "Init energy: " << scave.getEnergyPoints() << std::endl;

	for (int i = 0; i < 25; i++)
	{
		if (i % 5 == 0)
			std::cout << "Action " << (i + 1) << ": " << scave.getEnergyPoints() << std::endl;
		if (i % 2 == 0)
			scave.attack("Target");
		else
			scave.beRepaired(1);
	}
	std::cout << "Final energy: " << scave.getEnergyPoints() << std::endl;
	scave.attack("Target");
	scave.guardGate();
	std::cout << std::endl;

	std::cout << "==== TEST 8: Mort ====" << std::endl;

	ScavTrap	deadScav("Scav");
	deadScav.takeDamage(150);
	std::cout << "HitPoints afte fatal damage: " << deadScav.getHitPoints() << std::endl;

	deadScav.attack("Target");
	deadScav.beRepaired(10);
	deadScav.guardGate();
	std::cout << std::endl;

	std::cout << "==== TEST 9: Polymorphisme ====" << std::endl;

	ClapTrap*	polyFirst = new ClapTrap("PolyClap");
	ClapTrap*	polySec = new ScavTrap("PolyScav");

	std::cout << "ClapTrap attack: " << std::endl;
	polyFirst->attack("Target");
	
	std::cout << "ScavTrap attack: " << std::endl;
	polySec->attack("Target");

	delete polyFirst;
	delete polySec;
	std::cout << std::endl;
	std::cout << "==== FIN DES TESTS ====" << std::endl;

	return (0);
}
