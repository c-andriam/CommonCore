/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:08:26 by candriam          #+#    #+#             */
/*   Updated: 2025/03/21 15:45:26 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl	Harl;

	if (argc != 2)
	{
		Harl.complain("DEBUG");
		Harl.complain("INFO");
		Harl.complain("WARNING");
		Harl.complain("ERROR");
		Harl.complain("OTHER");
		return (0);
	}
	Harl.complain(argv[1]);
	return (0);
}
