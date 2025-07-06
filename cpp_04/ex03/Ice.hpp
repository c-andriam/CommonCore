/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 09:14:46 by candriam          #+#    #+#             */
/*   Updated: 2025/05/31 09:24:32 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ICE_HPP__
# define __ICE_HPP__

# include "AMateria.hpp"
# include "ICharacter.hpp"

class	Ice : public AMateria
{
	public:

		Ice();
		Ice( Ice const& copy );
		Ice&	operator=( Ice const& other );
		~Ice();

		AMateria*	clone() const;
		void		use( ICharacter& target );
};

#endif
