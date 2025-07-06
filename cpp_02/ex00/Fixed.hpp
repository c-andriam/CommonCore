/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 23:37:49 by candriam          #+#    #+#             */
/*   Updated: 2025/03/22 04:00:11 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_HPP__
# define __FIXED_HPP__

class	Fixed
{
	public:

		Fixed( void );
		Fixed( Fixed const& copy );
		Fixed& operator=( Fixed const& copy );
		~Fixed( void );

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

	private:

		int					_data;
		static const int	_fractBits;
};

#endif
