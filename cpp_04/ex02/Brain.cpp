/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 13:17:48 by candriam          #+#    #+#             */
/*   Updated: 2025/05/25 14:22:19 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>
#include <string>

Brain::Brain()
{
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain( const Brain& copy )
{
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		_ideas[i] = copy._ideas[i];
}

Brain&	Brain::operator=( const Brain& other )
{
	std::cout << "Brain assignment operator called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
		{
			_ideas[i] = other._ideas[i];
		}
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

void	Brain::setIdea( int index, const std::string& idea )
{
	if (index >= 0 && index < 100)
		_ideas[index] = idea;
	else
		std::cerr << "Index error" << std::endl;
}

std::string	Brain::getIdea( int index ) const
{
	if (index >= 0 && index < 100)
		return (_ideas[index]);
	std::cerr << "Index error" << std::endl;
	return ("");
}

const std::string*	Brain::getIdeas( ) const
{
	return (_ideas);
}
