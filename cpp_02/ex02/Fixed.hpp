/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 11:34:51 by candriam          #+#    #+#             */
/*   Updated: 2025/03/23 15:54:01 by candriam         ###   ########.fr       */
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
		Fixed( float const& value );
		Fixed( int const& value );
		Fixed&	operator=( Fixed const& fixed );
		
		bool	operator>( Fixed const& fixed ) const;
		bool	operator<( Fixed const& fixed ) const;
		bool	operator>=( Fixed const& fixed ) const;
		bool	operator<=( Fixed const& fixed ) const;
		bool	operator==( Fixed const& fixed ) const;
		bool	operator!=( Fixed const& fixed ) const;

		Fixed	operator+( Fixed const& fixed ) const;
		Fixed	operator-( Fixed const& fixed ) const;
		Fixed	operator*( Fixed const& fixed ) const;
		Fixed	operator/( Fixed const& fixed ) const;

		Fixed&	operator++( void );
		Fixed&	operator--( void );
		Fixed	operator++( int );
		Fixed	operator--( int );

		~Fixed( void );

		static Fixed&		min( Fixed& a, Fixed& b );
		static const Fixed&	min( Fixed const& a, Fixed const& b );
		static Fixed&		max( Fixed& a, Fixed& b );
		static const Fixed&	max( Fixed const& a, Fixed const& b );

		int		toInt( void ) const;
		float	tofloat( void ) const;

		static int	getFractbits( void );
		int			getRawbits( void ) const;

	private:

		int					_data;
		static const int	_fractBits;
};

std::ostream&	operator<<( std::ostream& flux, Fixed const& fixed );

#endif
