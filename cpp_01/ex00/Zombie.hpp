/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 08:37:43 by candriam          #+#    #+#             */
/*   Updated: 2025/03/18 10:00:08 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class	Zombie
{
	public:

		Zombie( std::string name );
		~Zombie( void );

		void	announce( void );

	private:

		std::string	_name;

};

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

#endif
