/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 06:25:08 by candriam          #+#    #+#             */
/*   Updated: 2025/03/21 15:38:24 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HARL_HPP__
# define __HARL_HPP__

# include <string>

class	Harl
{
	private:

		void	_debug( void );
		void	_info( void );
		void	_warning( void );
		void	_error( void );

	public:

		Harl( void );
		~Harl( void );
		
		void	complain( std::string level );
};

#endif
