/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 00:55:38 by candriam          #+#    #+#             */
/*   Updated: 2025/04/05 00:59:04 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DIAMONDTRAP_HPP__
# define __DIAMONDTRAP_HPP__
# include "FragTrap.hpp"
# include "ScavTrap.hpp"
# include <string>

class	DiamondTrap : public ScavTrap, public FragTrap
{
	private:

		std::string	_name;

	public:
		DiamondTrap( void );
		DiamondTrap( std::string name );
		DiamondTrap( DiamondTrap const& copy );
		DiamondTrap&	operator=( DiamondTrap const& copy );
		~DiamondTrap( void );

		void	attack( const std::string& target );
		void	whoAmI( void );
		std::string	getDiamondName( void ) const;
};

#endif
