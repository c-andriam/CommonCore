/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 10:36:21 by candriam          #+#    #+#             */
/*   Updated: 2025/05/24 10:46:47 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WRONGCAT_HPP__
# define __WRONGCAT_HPP__

# include "WrongAnimal.hpp"

class	WrongCat: public WrongAnimal
{
	public:

		WrongCat( void );
		WrongCat( WrongCat const& copy );
		WrongCat&	operator=( WrongCat const& a );
		~WrongCat( void );

		void	makeSound( void ) const;
};

#endif
