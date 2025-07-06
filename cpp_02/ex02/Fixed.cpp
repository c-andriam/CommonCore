/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 11:59:40 by candriam          #+#    #+#             */
/*   Updated: 2025/03/23 16:06:39 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>
#include <ostream>

const int	Fixed::_fractBits = 8;

Fixed::Fixed( void ) : _data(0)
{
}

Fixed::Fixed( Fixed const& fixed ) : _data(fixed._data)
{
}

Fixed::Fixed( float const& value ) : _data(static_cast<int>(roundf(value * (1 << getFractbits()))))
{
}

Fixed::Fixed( int const& value ) : _data((value) * (1 << getFractbits()))
{
}

Fixed&	Fixed::operator=( Fixed const& fixed )
{
	if (this != &fixed)
	{
		*this = fixed;
	}
	return (*this);
}

Fixed	Fixed::operator*( Fixed const& fixed ) const
{
	Fixed	result;
	result._data = (this->_data * fixed.getRawbits()) >> getFractbits();
	return (result);
}

Fixed	Fixed::operator+( Fixed const& fixed ) const
{
	Fixed	result;
	result._data = (this->_data + fixed.getRawbits());
	return (result);
}

Fixed	Fixed::operator-( Fixed const& fixed ) const
{
	Fixed	result;
	result._data = (this->_data - fixed.getRawbits());
	return (result);
}

Fixed	Fixed::operator/( Fixed const& fixed ) const
{
	Fixed	result;
	result._data = (getRawbits() << getFractbits()) / fixed.getRawbits();
	return (result);
}

bool	Fixed::operator>( Fixed const& fixed ) const
{
	return (this->_data > fixed.getRawbits());
}

bool	Fixed::operator<( Fixed const& fixed ) const
{
	return (this->_data < fixed.getRawbits());
}

bool	Fixed::operator>=( Fixed const& fixed ) const
{
	return (this->_data >= fixed.getRawbits());
}

bool	Fixed::operator<=( Fixed const& fixed ) const
{
	return (this->_data <= fixed.getRawbits());
}

bool	Fixed::operator==( Fixed const& fixed ) const
{
	return (this->_data == fixed.getRawbits());
}

bool	Fixed::operator!=( Fixed const& fixed ) const
{
	return (this->_data != fixed.getRawbits());
}

Fixed&	Fixed::operator++( void )
{
	this->_data += 1;
	return (*this);
}

Fixed	Fixed::operator++( int )
{
	Fixed	copy(*this);
	this->_data += 1;
	return (copy);
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

Fixed&	Fixed::min( Fixed& a, Fixed& b )
{
	return ((a.getRawbits() < b.getRawbits()) ? a : b);
}

Fixed&	Fixed::max( Fixed& a, Fixed& b )
{
	return ((a.getRawbits() > b.getRawbits()) ? a : b);
}

const Fixed&	Fixed::min( Fixed const& a, Fixed const& b )
{
	return ((a.getRawbits() < b.getRawbits()) ? a : b);
}

const Fixed&	Fixed::max( Fixed const& a, Fixed const& b )
{
	return ((a.getRawbits() > b.getRawbits()) ? a : b);
}

std::ostream&	operator<<( std::ostream& flux, Fixed const& fixed )
{
	flux << static_cast<float>(fixed.getRawbits()) / (1 << Fixed::getFractbits());
	return (flux);
}

float	Fixed::tofloat( void ) const
{
	return (static_cast<float>(this->_data) / (1 << getFractbits()));
}

int	Fixed::toInt( void ) const
{
	return (static_cast<int>(this->_data) / (1 << getFractbits()));
}

int	Fixed::getRawbits() const
{
	return (this->_data);
}

int	Fixed::getFractbits( void )
{
	return (Fixed::_fractBits);
}

Fixed::~Fixed( void )
{
}
