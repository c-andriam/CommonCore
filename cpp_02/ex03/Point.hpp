/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 18:15:45 by candriam          #+#    #+#             */
/*   Updated: 2025/03/24 17:29:04 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __POINT_HPP__
# define __POINT_HPP__

#include "Fixed.hpp"
#include <ostream>

class	Point
{
	public:

		Point( void );
		Point( Point const& point );
		Point&	operator=( Point const& point );
		Point( float const& a, float const& b );
		~Point( void );

		Point	operator-( Point const& a ) const;
		Point	operator*( Point const& a ) const;
		Point( Point const& a, Point const& b );
		static float	cross_product( Point const& a, Point const& b );

		Fixed	getX( void ) const;
		Fixed	getY( void ) const;

	private:

		Fixed const	_x;
		Fixed const	_y;

};

std::ostream&	operator<<( std::ostream& flux, Point const& point );

bool	bsp( Point const a, Point const b, Point const c, Point const point );


#endif
