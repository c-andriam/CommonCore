/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 17:46:07 by candriam          #+#    #+#             */
/*   Updated: 2025/03/24 17:43:11 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

int	main( void )
{
	Point	a(-6, 6);
	Point	b(2, 4);
	Point	c(-6, -4);
	Point	point(-5.999, 2);

	if (bsp(a, b, c, point) == true)
		std::cout << std::endl << "Result is 'true'" << std::endl;
	else
		std::cout << std::endl << "Result is 'false'" << std::endl;
	return (0);
}
