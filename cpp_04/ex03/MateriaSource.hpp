/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 08:43:38 by candriam          #+#    #+#             */
/*   Updated: 2025/05/31 10:34:19 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MATERIASOURCE_HPP__
# define __MATERIASOURCE_HPP__

# include "AMateria.hpp"
# include "IMateriaSource.hpp"

class	MateriaSource : public IMateriaSource
{
	private:
		AMateria* _materias[4];

	public:
		MateriaSource();
		MateriaSource( MateriaSource const& copy );
		MateriaSource&	operator=( MateriaSource const& other );
		~MateriaSource();

		void		learnMateria( AMateria* m );
		AMateria*	createMateria( std::string const& type );
};

#endif
