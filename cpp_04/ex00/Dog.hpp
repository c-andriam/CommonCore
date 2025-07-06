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

class	Dog: public Animal
{
	public:

		Dog( void );
		Dog( Dog const& copy );
		Dog&	operator=( Dog const& a );
		~Dog( void );

		void	makeSound( void ) const;
};

#endif
