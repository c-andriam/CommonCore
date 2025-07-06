/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 08:32:52 by candriam          #+#    #+#             */
/*   Updated: 2025/03/23 10:52:43 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include <iostream>
#include "Fixed.hpp"


const int Fixed::_fractBits = 8;

Fixed::Fixed( void ) : _data(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( Fixed const& copy )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed&	Fixed::operator=( const Fixed& copy )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		this->_data = copy._data;
	}
	return (*this);
}

Fixed::Fixed( float const& value ) : _data(static_cast<int>(roundf(value * (1 << getFractbits()))))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed( int const& value ) : _data((value) * (1 << getFractbits()))
{
	std::cout << "Int constructor called" << std::endl;
}

std::ostream&	operator<<( std::ostream& flux, Fixed const& fixed )
{
	flux << static_cast<float>(fixed.getRawbits()) / (1 << Fixed::getFractbits());
	return (flux);
}

float	Fixed::tofloat( void ) const
{
	return ((static_cast<float>(getRawbits())) / (1 << getFractbits()));
}

int	Fixed::toInt( void ) const
{
	return (static_cast<int>(getRawbits()) / (1 << getFractbits()));
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawbits() const
{
	return (this->_data);
}

int	Fixed::getFractbits()
{
	return (Fixed::_fractBits);
}