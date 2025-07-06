/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 13:35:34 by candriam          #+#    #+#             */
/*   Updated: 2025/04/10 19:13:54 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ANIMAL_HPP__
# define __ANIMAL_HPP__

# include <string>

class	Animal
{
	protected:

		std::string	type_;

	public:

		Animal( void );
		Animal( const std::string	&type );
		Animal( Animal const& copy );
		Animal&	operator=( Animal const& a );
		virtual ~Animal( void );

		void		setType( const std::string& type );
		std::string	getType( void ) const;
		virtual void		makeSound( void ) const;
};

#endif
