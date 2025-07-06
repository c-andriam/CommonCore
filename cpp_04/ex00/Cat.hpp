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

class	Cat: public Animal
{
	public:

		Cat( void );
		Cat( Cat const& copy );
		Cat&	operator=( Cat const& a );
		~Cat( void );

		void	makeSound( void ) const;
};

#endif
