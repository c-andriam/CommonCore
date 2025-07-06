/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 13:29:17 by candriam          #+#    #+#             */
/*   Updated: 2025/05/24 13:21:47 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	std::cout << "======= TEST DES CONSTRUCTEURS =======" << std::endl;

	std::cout << std::endl << "- - - Construction des objets de base - - -" << std::endl;
	const Animal*		meta = new Animal();
	const WrongAnimal*	wrong = new WrongAnimal();

	std::cout << std::endl << "- - - Construction des objets derivees - - -" << std::endl;
	const Animal*		dog = new Dog();
	const Animal*		cat = new Cat();
	const WrongAnimal*	wrongCat = new WrongCat();

	std::cout << std::endl << "======= TEST DES TYPES =======" << std::endl;
	std::cout << "Type de meta: " << meta->getType() << std::endl;
	std::cout << "Type de dog: " << dog->getType() << std::endl;
	std::cout << "Type de cat: " << cat->getType() << std::endl;
	std::cout << "Type de wrong: " << wrong->getType() << std::endl;
	std::cout << "Type de wrongCat: " << wrongCat->getType() << std::endl;

	std::cout << std::endl << "======= TEST DU POLYMORPHISME =======" << std::endl;

	std::cout << std::endl << "- - - Test des sons via pointeurs de classe de base - - -" << std::endl;
	std::cout << "meta->makeSound(): ";
	meta->makeSound();

	std::cout << "dog->makeSound(): ";
	dog->makeSound();

	std::cout << "cat->makeSound(): ";
	cat->makeSound();

	std::cout << "wrong->makeSound(): ";
	wrong->makeSound();

	std::cout << "wrongCat->makeSound(): ";
	wrongCat->makeSound();
	
	std::cout << std::endl << "- - - Test avec acces direct aux objets derivees - - -" << std::endl;
	
	Dog			directDog;
	Cat			directCat;
	WrongCat	directWrongCat;

	std::cout << "directDog.getType(): " << directDog.getType() << std::endl;
	std::cout << "directCat.getType(): " << directCat.getType() << std::endl;
	std::cout << "directWrongCat.getType(): " << directWrongCat.getType() << std::endl;

	std::cout << "directDog.makeSound(): ";
	directDog.makeSound();

	std::cout << "directCat.makeSound(): ";
	directCat.makeSound();

	std::cout << "directWrongCat.makeSound(): ";
	directWrongCat.makeSound();

	std::cout << std::endl << "- - - Test du slicing (perte du POLYMORPHISME) - - -" << std::endl;

	Animal	animalFromDog = directDog;
	Animal	animalFromCat = directCat;

	std::cout << "animalFromDog.getType(): " << animalFromDog.getType() << std::endl;
	std::cout << "animalFromDog.makeSound(): ";
	animalFromDog.makeSound();

	std::cout << "animalFromCat.getType(): " << animalFromCat.getType() << std::endl;
	std::cout << "animalFromCat.makeSound(): ";
	animalFromCat.makeSound();

	std::cout << std::endl << "- - - Comparaison des comportements Wrong vs Normal - - -" << std::endl;

	const Animal*	animals[4] = { meta, dog, cat, new Animal()};
	const WrongAnimal*	wrongAnimals[3] = {wrong, wrongCat, new WrongAnimal()};

	std::cout << std::endl << "Boucle sur animaux normaux (polymorphisme attendu):" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		std::cout << "Animal " << i << " (type: " << animals[i]->getType() << ") fait: ";
		animals[i]->makeSound();
	}

	std::cout << std::endl << "Boucle sur wrong animaux (pas de polymorphisme attendu pour wrongCat):" << std::endl;
	for (int i = 0; i < 3; i++)
	{
		std::cout << "WrongAnimal " << i << " (type: " << wrongAnimals[i]->getType() << ") fait: ";
		wrongAnimals[i]->makeSound();
	}

	std::cout << std::endl << "======= DESTRUCTION DES OBJETS =======" << std::endl;

	delete meta;
	delete dog;
	delete cat;
	delete wrong;
	delete wrongCat;
	delete animals[3];
	delete wrongAnimals[2];

	std::cout << std::endl << "======= TEST TERMINE =======" << std::endl;
	return (0);
}
