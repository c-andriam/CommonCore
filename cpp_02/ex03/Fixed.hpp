/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:43:05 by candriam          #+#    #+#             */
/*   Updated: 2025/03/24 16:05:29 by candriam         ###   ########.fr       */
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
		~Fixed( void );
		Fixed( const int& value );
		Fixed( const float& value );

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	tofloat( void ) const;
		int		toInt( void ) const;

		bool	operator>( Fixed const& a ) const;
		bool	operator<( Fixed const& a ) const;
		bool	operator>=( Fixed const& a ) const;
		bool	operator<=( Fixed const& a ) const;
		bool	operator==( Fixed const& a ) const;
		bool	operator!=( Fixed const& a ) const;

		Fixed	operator+( Fixed const& a ) const;
		Fixed	operator-( Fixed const& a ) const;
		Fixed	operator*( Fixed const& a ) const;
		Fixed	operator/( Fixed const& a ) const;

		Fixed&	operator++( void );
		Fixed&	operator--( void );
		Fixed	operator--( int );
		Fixed	operator++( int );

		static Fixed		min( Fixed& a, Fixed& b );
		static Fixed const	min( Fixed const& a, Fixed const& b );
		static Fixed		max( Fixed& a, Fixed& b );
		static Fixed const	max( Fixed const& a, Fixed const& b );

		static int	getFractbits( void );
		int			getRawbits( void ) const;


		operator float() const;
		
	private:

		int					_data;
		static const int	_fractBits;

};

std::ostream&	operator<<( std::ostream& flux, Fixed const& fixed );

#endif
