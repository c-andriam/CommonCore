/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 23:52:38 by candriam          #+#    #+#             */
/*   Updated: 2025/03/25 15:46:07 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SCAVTRAP_HPP__
# define __SCAVTRAP_HPP__

#include "ClapTrap.hpp"
#include <string>

class	ScavTrap : public ClapTrap
{
	public:
	
		ScavTrap( void );
		ScavTrap( std::string name );
		ScavTrap( ScavTrap const& copy );
		ScavTrap&	operator=( ScavTrap const& copy );
		~ScavTrap( void );

		void	attack( const std::string& target );
		void	guardGate( void ) const;
};

#endif
