/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:26:00 by candriam          #+#    #+#             */
/*   Updated: 2025/03/24 17:42:18 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

bool	bsp( Point const a, Point const b, Point const c, Point const point )
{
	Point	ab(a, b);
	Point	bc(b, c);
	Point	ca(c, a);
	Point	ap(a, point);
	Point	bp(b, point);
	Point	cp(c, point);

	float	x = ab.cross_product(ab, ap);
	float	y = bc.cross_product(bc, bp);
	float	z = ca.cross_product(ca, cp);

	std::cout << std::endl << "A : " << a << std::endl << "B : " << b
		<< std::endl << "C : " << c << std::endl << "P : " << point << std::endl;
	std::cout << std::endl << "AB : " << ab << std::endl << "BC : " << bc
		<< std::endl << "CA : " << ca << std::endl << std::endl;
	std::cout << "AP : " << ap << std::endl << "BP : " << bp
		<< std::endl << "CP : " << cp << std::endl << std::endl;
	std::cout << "ABxAP : " << x << std::endl << "BCxBP : " << y
		<< std::endl << "CAxCP : " << z << std::endl;
	if ((x > 0 && y > 0 && z > 0) || (x < 0 && y < 0 && z < 0))
		return (true);
	return (false);
}
