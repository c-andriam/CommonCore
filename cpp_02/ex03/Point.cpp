/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 09:21:36 by candriam          #+#    #+#             */
/*   Updated: 2025/03/24 17:28:56 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iomanip>

Point::Point( void ) : _x(0), _y(0)
{
}

Point::Point( Point const& point ) : _x(point.getX()), _y(point.getY())
{
}

Point&	Point::operator=( Point const& point )
{
	if (this != &point)
	{
		*this = point;
	}
	return (*this);
}

Point::Point( Point const& a, Point const& b ) : _x(static_cast<float>(b.getX() - a.getX())), _y(static_cast<float>(b.getY() - a.getY()))
{
}

Fixed	Point::getX( void ) const
{
	return (_x);
}

Fixed	Point::getY( void ) const
{
	return (_y);
}

std::ostream&	operator<<( std::ostream& flux, Point const& point )
{
	flux << "(" << std::setprecision(3) << point.getX() << ", " << point.getY() << ")";
	return (flux);
}

Point::Point( float const& a, float const& b ) : _x(a), _y(b)
{
}

Point	Point::operator-( Point const& a ) const
{
	return (Point(static_cast<float>(getX()) - static_cast<float>(a.getX()),
			static_cast<float>(getY()) - static_cast<float>(a.getY())));
}

Point	Point::operator*( Point const& a ) const
{
	return (Point(static_cast<float>(getX()) * static_cast<float>(a.getX()),
				static_cast<float>(getY()) * static_cast<float>(a.getY())));
}

float	Point::cross_product( Point const& a, Point const& b )
{
	return ((a.getX() * b.getY()) - (a.getY() * b.getX()));
}

Point::~Point( void )
{
}
