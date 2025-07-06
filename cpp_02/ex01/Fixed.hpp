/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 04:07:41 by candriam          #+#    #+#             */
/*   Updated: 2025/03/23 09:53:28 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_HPP__
# define __FIXED_HPP__

#include <ostream>

class	Fixed
{
	public:

		Fixed( void );
		Fixed( Fixed const& copy );
		Fixed&	operator=( Fixed const& copy );
		Fixed( int const& value );
		Fixed( float const& value );
		~Fixed( void );

		int		getRawbits() const;
		static int	getFractbits();

		float	tofloat( void ) const;
		int		toInt( void ) const;

	private:

		int					_data;
		static const int	_fractBits;
};

std::ostream&	operator<<( std::ostream& flux, Fixed const& fixed );

#endif
