/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 10:15:43 by candriam          #+#    #+#             */
/*   Updated: 2025/05/24 10:17:43 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DOG_HPP__
# define __DOG_HPP__

# include "Animal.hpp"
# include "Brain.hpp"
#include <string>

class	Dog: public Animal
{
	public:

		Dog( );
		Dog( Dog const& copy );
		Dog&	operator=( Dog const& a );
		~Dog( );

		void	makeSound( void ) const;
		void	setBrainIdea( int index, const std::string& idea);
		std::string	getBrainIdea( int index ) const;

	private:

		Brain*	_brain;
};

#endif
