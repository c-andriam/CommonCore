/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 08:41:12 by candriam          #+#    #+#             */
/*   Updated: 2025/05/31 08:42:59 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __IMATERIASOURCE_HPP__
# define __IMATERIASOURCE_HPP__

# include <string>

class	IMateriaSource
{
	public:
		virtual ~IMateriaSource() {}
		virtual void			learnMateria( class AMateria* m ) = 0;
		virtual class AMateria*	createMateria( std::string const& type ) = 0;
};

#endif
