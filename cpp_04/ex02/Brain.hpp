/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 12:53:40 by candriam          #+#    #+#             */
/*   Updated: 2025/05/25 14:16:43 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BRAIN_HPP__
#define __BRAIN_HPP__

# include <string>

class	Brain
{
	private:
		std::string _ideas[100];

	public:
		Brain();
		Brain( const Brain& copy );
		Brain& operator=( const Brain& other );
		~Brain();

		void	setIdea( int index, const std::string& idea );
		std::string	getIdea( int index ) const;
		const std::string* getIdeas( ) const;
};

#endif
