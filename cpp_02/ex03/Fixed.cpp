/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:46:27 by candriam          #+#    #+#             */
/*   Updated: 2025/03/24 16:05:24 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>
#include <iostream>

const int	Fixed::_fractBits = 8;

Fixed::Fixed( void ) : _data(0)
{
}

Fixed::Fixed( Fixed const& copy ) : _data(copy._data)
{
}

Fixed&	Fixed::operator=( Fixed const& copy )
{
	if (this != &copy)
	{
		*this = copy;
	}
	return (*this);
}

Fixed::Fixed( float const& value ) : _data(static_cast<int>(roundf(value * (1 << _fractBits))))
{
}

Fixed::Fixed( int const& value ) : _data(value * (1 << _fractBits))
{
}

int	Fixed::getRawBits( void ) const
{
	return (this->_data);
}

void	Fixed::setRawBits( const int raw )
{
	this->_data = raw;
}

float	Fixed::tofloat( void ) const
{
	return (static_cast<float>(this->_data) / (1 << _fractBits));
}

Fixed::operator float() const
{
	return static_cast<float>(getRawbits()) / (1 << Fixed::getFractbits());
}

int	Fixed::toInt( void ) const
{
	return (static_cast<int>(this->_data) / (1 << _fractBits));
}

std::ostream&	operator<<( std::ostream& flux, Fixed const& fixed )
{
	flux << static_cast<float>(fixed.getRawbits()) / (1 << Fixed::getFractbits());
	return (flux);
}

bool	Fixed::operator<( Fixed const& a ) const
{
	return (this->_data < a._data);
}

bool	Fixed::operator>( Fixed const& a ) const
{
	return (this->_data > a._data);
}

bool	Fixed::operator<=( Fixed const& a ) const
{
	return (this->_data <= a._data);
}

bool	Fixed::operator>=( Fixed const& a ) const
{
	return (this->_data >= a._data);
}

bool	Fixed::operator==( Fixed const& a ) const
{
	return (this->_data == a._data);
}

bool	Fixed::operator!=( Fixed const& a ) const
{
	return (this->_data != a._data);
}

Fixed	Fixed::operator+( Fixed const& a ) const
{
	Fixed	resutlt;
	resutlt._data = this->_data + a._data;
	return (resutlt);
}

Fixed	Fixed::operator-( Fixed const& a ) const
{
	Fixed	res;
	res._data = this->_data - a._data;
	return (res);
}

Fixed	Fixed::operator*( Fixed const& a ) const
{
	Fixed	res;
	res._data = (this->_data * a._data) >> (_fractBits);
	return (res);
}

Fixed	Fixed::operator/( Fixed const& a ) const
{
	Fixed	res;
	res._data = (this->_data << (_fractBits)) / a._data;
	return (res);
}

Fixed&	Fixed::operator++( void )
{
	this->_data += 1;
	return (*this);
}

Fixed&	Fixed::operator--( void )
{
	this->_data -= 1;
	return (*this);
}

Fixed	Fixed::operator--( int )
{
	Fixed	copy(*this);
	this->_data -= 1;
	return (copy);
}

Fixed	Fixed::operator++( int )
{
	Fixed	copy(*this);
	this->_data += 1;
	return (copy);
}

Fixed	Fixed::max( Fixed& a, Fixed& b )
{
	return ((a._data > b._data) ? a : b);
}

Fixed	Fixed::min( Fixed& a, Fixed& b )
{
	return ((a._data < b._data) ? a : b);
}

const Fixed	Fixed::max( Fixed const& a, Fixed const& b )
{
	return ((a._data > b._data) ? a : b);
}

const Fixed	Fixed::min( Fixed const& a, Fixed const& b )
{
	return ((a._data < b._data) ? a : b);
}

int	Fixed::getFractbits( void )
{
	return (Fixed::_fractBits);
}

int	Fixed::getRawbits( void ) const
{
	return (this->_data);
}

Fixed::~Fixed( void )
{
}
