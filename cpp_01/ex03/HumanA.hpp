/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 01:20:55 by candriam          #+#    #+#             */
/*   Updated: 2025/03/19 03:39:40 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HUMANA_H__
# define __HUMANA_H__

# include "Weapon.hpp"
# include <string>

class	HumanA
{
	private:

		std::string	_name;
		Weapon&		_weapon;

	public:

		HumanA( std::string const& name, Weapon& weapon );
		~HumanA( void );

		void	attack( void ) const;
};

#endif
