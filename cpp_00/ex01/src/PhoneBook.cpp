/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:44:50 by candriam          #+#    #+#             */
/*   Updated: 2025/03/18 16:12:30 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PhoneBook.hpp"
#include "../inc/Contact.hpp"
#include <cstddef>
#include <iomanip>
#include <iostream>
#include <cstdlib>

PhoneBook::PhoneBook( void )
{
	_count = 0;
	_oldest = 0;
	_max_contact = 8;
	return;
}

PhoneBook::~PhoneBook( void )
{
	return;
}

bool	PhoneBook::_isPhoneBookEmpty( void ) const
{
	return (_count == 0);
}

void	PhoneBook::_emptyMessage( void ) const
{
	std::cout << "Your PhoneBook is empty. Please add one or more contact before consulting your PhoneBook"
		<< std::endl;
}

bool	PhoneBook::_isPhoneBookFull( void ) const
{
	return (_count >= _max_contact);
}

void	PhoneBook::_fullMessage( void ) const
{
	std::cout << "Warning!! your PhoneBook is full, you risk to lose your oldest contact"
		<< std::endl;
}

void	PhoneBook::_insistingMessage( void ) const
{
	std::cout << "continue or abort (c / a) ";
}

void	PhoneBook::_abortMessage( void ) const
{
	std::cout << "aborted" << std::endl;
}

void	PhoneBook::_continueMessage( void ) const
{
	std::cout << "continued" << std::endl;
}

void	PhoneBook::_noneMessage( void ) const
{
	std::cout << "* PS: <none> ARE ACCEPTED FOR NOTHING. *" << std::endl;
}

void	PhoneBook::_phoneNumberMessage( void ) const
{
	std::cout << "* PS: ONLY NUMERIC ARE ACCEPTED HERE. *" << std::endl;
}

std::string	PhoneBook::_getInput( std::string input ) const
{
	if (!std::getline(std::cin, input))
		exit(1);
	return (input);
}

int	PhoneBook::_chooseOption( std::string answer, int state) const
{
	answer = _getInput(answer);
	if (answer == "a")
	{
		_abortMessage();
		state = 0;
	}
	else if (answer == "c")
	{
		_continueMessage();
		state = 1;
	}
	else
	{
		_insistingMessage();
		state = -1;
	}
	return (state);
}

bool	PhoneBook::_confirmingProcess( void ) const
{
	std::string answer;
	int	state = true;
	_fullMessage();
	_insistingMessage();
	state = _chooseOption(answer, state);
	while (state == -1)
		state = _chooseOption(answer, state);
	return (state);
}

std::string	PhoneBook::_insistingGetInput( std::string message , std::string input ) const
{
	do
	{
		std::cout << message;
		input = _getInput(input);
	}
	while (input.empty());
	return (input);
}

std::string	PhoneBook::_checkIsSpace( std::string input ) const
{
	size_t i = 0;
	while (i < input.length() && std::isspace(input[i]))
		i++;
	std::string	result = input.substr(i);
	return (result);
}

bool	PhoneBook::_isSpace( const std::string input ) const
{
	int	index = 0;
	while (input[index] == '\t' || input[index] == '\n' || input[index] == '\v'
			|| input[index] == '\f' || input[index] == '\r' || input[index] == ' ')
	{
		index++;
		return (true);
	}
	return (false);
}

bool	PhoneBook::_isDigit( const std::string input ) const
{
	for (size_t i = 0; i < input.length(); i++)
	{
		if (input[i] > '9' || input[i] < '0')
			return (false);
	}
	return (!input.empty());
}

void	PhoneBook::_firstName( int contact_index )
{
	std::string	first_name;
	Contact &newContact = _contacts[contact_index];
	do
	{
		first_name = _insistingGetInput( "Enter your first name (required) : ", first_name = _checkIsSpace(first_name));
		newContact.setFirstName(first_name);
	}
	while (_isSpace(first_name));
}

void	PhoneBook::_lastName( int contact_index )
{
	std::string	last_name;
	Contact &newContact = _contacts[contact_index];
	do
	{
		last_name = _insistingGetInput("Enter your last name (required) : ", last_name = _checkIsSpace(last_name));
		newContact.setLastName(last_name);
	}
	while (_isSpace(last_name));
}

void	PhoneBook::_nickName( int contact_index )
{
	std::string	nick_name;
	Contact &newContact = _contacts[contact_index];
	_noneMessage();
	do
	{
		nick_name = _insistingGetInput("Enter your nick name : ", nick_name = _checkIsSpace(nick_name));
		newContact.setNickName(nick_name);
	}
	while (_isSpace(nick_name));
}

void	PhoneBook::_phoneNumber( int contact_index )
{
	std::string	phone_number;
	Contact &newContact = _contacts[contact_index];
	do
	{
		phone_number = _insistingGetInput("Enter your phone number (required) : ", phone_number = _checkIsSpace(phone_number));
		newContact.setPhoneNumber(phone_number);
	}
	while (_isSpace(phone_number));// || _IsDigit(phone_number) == false);
}

void	PhoneBook::_darkestSecret( int contact_index )
{
	std::string	secret;
	Contact &newContact = _contacts[contact_index];
	_noneMessage();
	do
	{
		secret = _insistingGetInput("Enter your darkest secret : ", secret);
		newContact.setDarkestSecret(secret);
	}
	while (_isSpace(secret));
}

void	PhoneBook::_successMessage( void ) const
{
	std::cout << "Contact added successfully" << std::endl;
}

void	PhoneBook::_addingProcess( int index )
{
	_firstName(index);
	_lastName(index);
	_nickName(index);
	_phoneNumber(index);
	_darkestSecret(index);
	_successMessage();
}

void	PhoneBook::_setLines( int colWidth ) const
{
	std::cout << "|" << std::setfill('-') << std::setw(colWidth) << "" << "|"
		<< std::setw(colWidth) << "" << "|"
		<< std::setw(colWidth) << "" << "|"
		<< std::setw(colWidth) << "" << "|"
		<< std::setfill(' ') << std::endl;
}

void	PhoneBook::_setHeader( int colWidth ) const
{
	std::cout << "|" << std::setw(colWidth) << "Index" << "|"
		<< std::setw(colWidth) << "First name" << "|"
		<< std::setw(colWidth) << "Last name" << "|"
		<< std::setw(colWidth) << "Nick name" << "|"
		<< std::endl;
}

void	PhoneBook::_setArrays( int colWidth ) const
{
	_setLines(colWidth);
	_setHeader(colWidth);
	_setLines(colWidth);
}

std::string	PhoneBook::_truncatString( const std::string &str, size_t len) const
{
	if (str.length() > len)
		return (str.substr(0, len - 1) + ".");
	else
		return (str);
}

bool	PhoneBook::_isValidIndex( const char digit ) const
{
	int	index = digit - '0';
	return (index > 0 && index <= _count);
}

int	PhoneBook::_searchProcess( std::string to_search ) const
{
	if (to_search.length() == 1 && _isValidIndex(to_search[0]))
		return (1);
	else 
		return (0);
}

void	PhoneBook::addContact( void )
{
	int	index;

	if (_isPhoneBookFull())
	{
		if (_confirmingProcess() == false)
			return ;
		index = _oldest;
		_addingProcess(index);
		_oldest = (_oldest + 1) % _max_contact;
	}
	else
	{
		index = _count;
		_addingProcess(index);
		_count++;
	}
}

int	PhoneBook::displayContact( void ) const
{
	const int	colWidth = 10;
	if (_isPhoneBookEmpty())
	{
		_emptyMessage();
		return (0);
	}
	else
		_setArrays(colWidth);
	for (int i = 0; i < _count; i++)
	{
		const	Contact	&contact = _contacts[i];
		std::string	first_name = _truncatString(contact.getFirstName(), colWidth);
		std::string	last_name = _truncatString(contact.getLastName(), colWidth);
		std::string	nick_name = _truncatString(contact.getNickName(), colWidth);
		std::cout << "|" << std::right << std::setw(colWidth) << i + 1 << "|"
			<< std::setw(colWidth) << first_name << "|"
			<< std::setw(colWidth) << last_name << "|"
			<< std::setw(colWidth) << nick_name << "|"
			<< std::endl;
		_setLines(colWidth);
	}
	return (1);
}


void	PhoneBook::searchContact( void ) const
{
	std::string	to_search;
	do
		to_search = _insistingGetInput("Please enter contact index : ", to_search);
	while (to_search.empty() || _searchProcess(to_search) == 0);
	std::cout << std::setfill('-') << std::setw(14) << "" << "|" << "Contact information" << "|"
		<< std::setfill('-') << std::setw(14) << "" << std::endl;
	int index = std::atoi(to_search.c_str());
	_displayInfo(index);
}

void	PhoneBook::_displayInfo( int index ) const
{
	 const Contact	&contact = _contacts[index - 1];
	std::cout << " First name     : " << contact.getFirstName() << std::endl;
	std::cout << " Last name      : " << contact.getLastName() << std::endl;
	std::cout << " Nick name      : " << contact.getNickName() << std::endl;
	std::cout << " Phone number   : " << contact.getPhoneNumber() << std::endl;
	std::cout << " Darkest secret : " << contact.getDarkestSecret() << std::endl;
	std::cout << std::setfill('-') << std::setw(49) << "" << std::endl;
}
