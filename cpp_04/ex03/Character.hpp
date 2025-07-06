/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:47:11 by candriam          #+#    #+#             */
/*   Updated: 2025/05/31 10:09:51 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CHARACTER_HPP__
# define __CHARACTER_HPP__

# include "ICharacter.hpp"
# include "AMateria.hpp"
# include <string>

class Character : public ICharacter
{
	private:

		std::string	_name;
		AMateria*	_inventory[4];
		AMateria*	_unequiped[128];

	public:

		Character();
		Character( std::string const& name );
		Character( Character const& copy );
		Character&	operator=( Character const& other );
		virtual ~Character();

		std::string const&	getName() const;
		void	equip( AMateria* m );
		void	unequip( int index );
		void	use( int index, ICharacter& target );
};

#endif
