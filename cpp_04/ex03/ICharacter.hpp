/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:39:37 by candriam          #+#    #+#             */
/*   Updated: 2025/05/30 16:42:19 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ICHARACTER_HPP__
# define __ICHARACTER_HPP__

# include <string>

class AMateria;

class ICharacter
{
	public:
		
		virtual ~ICharacter() {}
		virtual std::string const&	getName() const = 0;
		virtual void	equip(class AMateria* m) = 0;
		virtual void	unequip(int idx) = 0;
		virtual void	use(int idx, class ICharacter& target) = 0;
};

#endif
