/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 02:02:58 by candriam          #+#    #+#             */
/*   Updated: 2025/03/19 03:52:01 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HUMANB_HPP__
# define __HUMANB_HPP__

#include "Weapon.hpp"
#include <string>
class	HumanB
{
	private:

		std::string	_name;
		Weapon*		_weapon;

	public:

		HumanB( std::string const& name );
		~HumanB( void );

		void	attack( void ) const;
		void	setWeapon( Weapon& weapon );
};

#endif
