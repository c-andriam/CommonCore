/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 19:08:32 by candriam          #+#    #+#             */
/*   Updated: 2025/05/30 10:32:18 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CAT_HPP__
# define __CAT_HPP__

# include "Animal.hpp"
# include "Brain.hpp"
#include <string>

class	Cat: public Animal
{
	public:

		Cat( void );
		Cat( Cat const& copy );
		Cat&	operator=( Cat const& a );
		~Cat( void );

		void	makeSound( void ) const;
		void	setBrainIdea( int index, const std::string& idea);
		std::string	getBrainIdea( int index ) const;

	private:

		Brain*	_brain;
};

#endif
