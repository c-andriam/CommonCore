/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 13:35:34 by candriam          #+#    #+#             */
/*   Updated: 2025/04/10 19:13:54 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __AANIMAL_HPP__
# define __AANIMAL_HPP__

# include <string>

class	AAnimal
{
	protected:

		std::string	type_;

	public:

		AAnimal( void );
		AAnimal( const std::string	&type );
		AAnimal( AAnimal const& copy );
		AAnimal&	operator=( AAnimal const& a );
		virtual ~AAnimal( void );

		void		setType( const std::string& type );
		std::string	getType( void ) const;
		virtual void		makeSound( void ) const = 0;
};

#endif
