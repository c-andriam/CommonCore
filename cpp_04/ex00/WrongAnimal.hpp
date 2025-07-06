/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 10:34:18 by candriam          #+#    #+#             */
/*   Updated: 2025/05/30 10:42:51 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WRONGANIMAL_HPP__
# define __WRONGANIMAL_HPP__

# include <string>

class	WrongAnimal
{
	protected:

		std::string	type_;

	public:

		WrongAnimal( void );
		WrongAnimal( const std::string	&type );
		WrongAnimal( WrongAnimal const& copy );
		WrongAnimal&	operator=( WrongAnimal const& a );
		virtual ~WrongAnimal( void );

		void		setType( const std::string& type );
		std::string	getType( void ) const;
		void		makeSound( void ) const;
};

#endif
