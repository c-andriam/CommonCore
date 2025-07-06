/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 15:54:02 by candriam          #+#    #+#             */
/*   Updated: 2025/05/31 10:28:09 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __AMATERIA_HPP__
# define __AMATERIA_HPP__

# include <string>
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:
		std::string	type_;

	public:
		AMateria();
		AMateria( std::string const & type );
		AMateria( AMateria const& copy );
		AMateria&	operator=( AMateria const& a );
		virtual ~AMateria();

		std::string const&	getType() const;

		virtual AMateria*	clone() const = 0;
		virtual void		use( class ICharacter& target );
};

#endif
