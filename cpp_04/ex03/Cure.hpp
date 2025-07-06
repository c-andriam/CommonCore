/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 09:19:49 by candriam          #+#    #+#             */
/*   Updated: 2025/05/31 09:23:03 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CURE_HPP__
# define __CURE_HPP__

# include "AMateria.hpp"
# include "ICharacter.hpp"

class	Cure : public AMateria
{
	public:

		Cure();
		Cure( Cure const& copy );
		Cure&	operator=( Cure const& other );
		~Cure();

		AMateria*	clone() const;
		void		use( ICharacter& target );
};

#endif
