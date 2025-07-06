/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 23:16:36 by candriam          #+#    #+#             */
/*   Updated: 2025/03/26 01:11:51 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FRAGTRAP_HPP__
# define __FRAGTRAP_HPP__

#include "ClapTrap.hpp"
#include <string>

class	FragTrap : virtual public ClapTrap
{
	public:
		
		FragTrap( void );
		FragTrap( std::string name );
		FragTrap( FragTrap const& copy );
		FragTrap&	operator=( FragTrap const& copy );
		~FragTrap( void );
	
		void	attack( const std::string& target );
		void	highFivesGuys( void ) const;
};

#endif
