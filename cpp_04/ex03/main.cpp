/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 15:00:47 by candriam          #+#    #+#             */
/*   Updated: 2025/05/31 11:00:45 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include <iostream>

int main()
{
	IMateriaSource*	src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	me->equip(src->createMateria("ice"));
	me->equip(src->createMateria("cure"));
	me->equip(src->createMateria("cure"));

	std::cout << "--------- Utilisation d'une materia non existante ---------" << std::endl;
	me->use(2, *bob);
	me->use(3, *bob);
	me->use(4, *bob);
	me->use(-1, *bob);

	std::cout << "-------- Unequip et re-equip ---------" << std::endl;

	me->unequip(1);
	me->use(1, *bob);

	AMateria* tmp2 = src->createMateria("cure");
	me->equip(tmp2);
	me->use(1, *bob);

	std::cout << "-------- Copie profonde des Character ---------" << std::endl;

	Character* original = new Character("original");
	original->equip(src->createMateria("ice"));
	Character* copy = new Character(*original);
	copy->use(0, *bob);
	delete original;
	copy->use(0, *bob);
	delete copy;

	delete tmp;
	delete bob;
	delete me;
	delete src;
	return (0);
}
