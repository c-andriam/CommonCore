/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:48:30 by candriam          #+#    #+#             */
/*   Updated: 2025/03/18 16:12:19 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Contact.hpp"
#include <string>

Contact::Contact( void )
{
}

Contact::~Contact( void )
{
}

void	Contact::setFirstName( const std::string &first_name )
{
	_first_name = first_name;
}

void	Contact::setLastName( const std::string &last_name )
{
	_last_name = last_name;
}

void	Contact::setNickName( const std::string &nick_name )
{
	_nick_name = nick_name;
}

void	Contact::setPhoneNumber( const std::string &number )
{
	_phone_number = number;
}

void	Contact::setDarkestSecret( const std::string &secret )
{
	_darkest_secret = secret;
}

std::string	Contact::getFirstName() const
{
	return (_first_name);
}

std::string	Contact::getLastName() const
{
	return (_last_name);
}

std::string	Contact::getNickName() const
{
	return (_nick_name);
}

std::string	Contact::getPhoneNumber() const
{
	return (_phone_number);
}

std::string	Contact::getDarkestSecret() const
{
	return (_darkest_secret);
}
