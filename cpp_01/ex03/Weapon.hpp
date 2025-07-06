/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 01:00:19 by candriam          #+#    #+#             */
/*   Updated: 2025/03/19 03:31:18 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WEAPON_HPP__
# define __WEAPON_HPP__

#include <string>
class	Weapon
{
	private:

		std::string	_type;

	public:

		Weapon( std::string const& type );
		~Weapon( void );

		std::string const&	getType( void ) const;
		void				setType( std::string const& type );

};

#endif
