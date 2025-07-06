/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 20:13:31 by candriam          #+#    #+#             */
/*   Updated: 2025/03/24 23:22:43 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CLAPTRAP_HPP__
# define __CLAPTRAP_HPP__

#include <iostream>
#include <string>

class	ClapTrap
{
	public:

		ClapTrap( void );
		ClapTrap( std::string name );
		ClapTrap( ClapTrap const& copy );
		ClapTrap&	operator=( ClapTrap const& copy );
		virtual ~ClapTrap( void );

		virtual void		attack( const std::string& target );
		void		takeDamage( unsigned int amount );
		void		beRepaired( unsigned int amount );

		std::string	getName( void ) const;
		int			getHitPoints( void ) const;
		int			getEnergyPoints( void ) const;
		int			getAttackDamage( void ) const;

	protected:

		std::string	_name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;

};

std::ostream&	operator<<( std::ostream& flux, ClapTrap const& a );

#endif
