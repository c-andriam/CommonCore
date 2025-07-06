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

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>
#include <sstream>
#include <string>
#define N 6

std::string	toString( int value )
{
	std::stringstream	ss;
	ss << value;
	return (ss.str());
}

int	main()
{
	Animal*	animals[N];

	for (int i = 0; i < N / 2; ++i)
		animals[i] = new Dog();
	for (int i = N / 2; i < N ; ++i)
		animals[i] = new Cat();

	for (int i = 0; i < N; i++)
	{
		std::string idea = "Idée numéro " + toString(i);
		if (animals[i]->getType() == "Dog")
			static_cast<Dog*>(animals[i])->setBrainIdea(0, idea);
		else if (animals[i]->getType() == "Cat")
			static_cast<Cat*>(animals[i])->setBrainIdea(0, idea);
	}

	for (int i = 0; i < N; i++)
	{
		std::cout << animals[i]->getType() << " 0: ";
		if (animals[i]->getType() == "Dog")
			std::cout << static_cast<Dog*>(animals[i])->getBrainIdea(0) << std::endl;
		else if (animals[i]->getType() == "Cat")
			std::cout << static_cast<Cat*>(animals[i])->getBrainIdea(0) << std::endl;
	}

	for (int i = 0; i < N; i++)
	{
		animals[i]->makeSound();
	}
	
	std::cout << std::endl << "Testing deep copy of Dog and Cat:" << std::endl;

	Dog* dog = new Dog();
	dog->setBrainIdea(0, "Balle");
	Dog* dog2 = new Dog(*dog);
	delete dog;
	dog2->setBrainIdea(0, "Baton");

	// std::cout << "dog brain: " << dog->getBrainIdea(0) << std::endl;
	std::cout << "dog2 brain: " << dog2->getBrainIdea(0) << std::endl;

	Cat* cat = new Cat();
	cat->setBrainIdea(0, "Boule de poils");
	Cat* cat2 = new Cat(*cat);
	cat2->setBrainIdea(0, "Balle de laine");

	std::cout << "cat brain: " << cat->getBrainIdea(0) << std::endl;
	std::cout << "cat2 brain: " << cat2->getBrainIdea(0) << std::endl;

	delete dog2;
	delete cat;
	delete cat2;

	for (int i = 0; i < N; ++i)
		delete animals[i];

	return (0);

}
