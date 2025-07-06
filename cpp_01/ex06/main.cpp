/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:29:35 by candriam          #+#    #+#             */
/*   Updated: 2025/03/21 16:32:38 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	Harl	Harl;
	if (argc != 2)
	{
		std::cerr << "usage : " << argv[0] << " DEBUG or INFO or WARNING or ERROR"
			<< std::endl;
		return (1);
	}
	else
		Harl.complain(argv[1]);
	return (0);
}
