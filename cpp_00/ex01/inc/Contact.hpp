/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:42:57 by candriam          #+#    #+#             */
/*   Updated: 2025/03/18 16:14:55 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

# include <string>

class	Contact
{
	public:

		Contact(void);
		~Contact(void);

		void		setFirstName( const std::string &first_name );
		void		setLastName( const std::string &last_name );
		void		setNickName( const std::string &nick_name );
		void		setPhoneNumber( const std::string &number );
		void		setDarkestSecret( const std::string &secret );

		std::string	getFirstName( void ) const;
		std::string	getLastName( void ) const;
		std::string	getNickName( void ) const;
		std::string	getPhoneNumber( void ) const;
		std::string	getDarkestSecret( void ) const;

	private:

		std::string	_first_name;
		std::string	_last_name;
		std::string	_nick_name;
		std::string	_darkest_secret;
		std::string	_phone_number;
		
};

#endif
