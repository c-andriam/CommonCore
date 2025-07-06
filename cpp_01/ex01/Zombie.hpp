/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:59:36 by candriam          #+#    #+#             */
/*   Updated: 2025/03/18 20:22:29 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <string>

class	Zombie
{
	public:
		
		Zombie( void );
		~Zombie( void );

		void		setZombieName( std::string name );
		std::string	getZombieName( void ) const;
		void		announce( void ) const;
	
	private:

		std::string	_name;
};

Zombie*	zombieHorde( int N, std::string name );

#endif
