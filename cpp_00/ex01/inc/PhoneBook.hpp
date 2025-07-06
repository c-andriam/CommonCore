/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:42:57 by candriam          #+#    #+#             */
/*   Updated: 2025/03/18 16:15:09 by candriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"
# include <string>

class	PhoneBook
{
	public:
		
		PhoneBook( void );
		~PhoneBook( void );
		
		void		addContact( void );
		void		searchContact( void ) const;
		int			displayContact( void ) const;

	private:
		
		int			_max_contact;
		int			_count;
		int			_oldest;
		Contact		_contacts[8];
		
		void		_displayInfo( int index ) const;
		void		_emptyMessage( void ) const;
		void		_phoneNumberMessage( void ) const;
		void		_fullMessage( void ) const;
		void		_insistingMessage( void ) const;
		void		_abortMessage( void ) const;
		void		_continueMessage( void ) const;
		void		_firstName( int contact_index );
		void		_lastName( int contact_index );
		void		_nickName( int contact_index );
		void		_phoneNumber( int contact_index );
		void		_darkestSecret( int contact_index );
		void		_successMessage( void ) const;
		void		_addingProcess( int contact_index );
		void		_setLines( int colWidth ) const;
		void		_setHeader( int colWidth ) const;
		void		_setArrays( int colWidth ) const;
		void		_noneMessage( void ) const;
		
		int			_searchProcess( std::string to_search ) const;
		int			_chooseOption( std::string answer, int state ) const;

		bool		_confirmingProcess( void ) const;
		bool		_isSpace( const std::string input ) const;
		bool		_isValidIndex( const char digit ) const;
		bool		_isDigit( const std::string input ) const;
		bool		_isPhoneBookEmpty( void ) const;
		bool		_isPhoneBookFull( void ) const;
		bool		_isDigit( const char digit ) const;

		std::string	_getInput( std::string input) const;
		std::string	_truncatString( const std::string &str, size_t len ) const;
		std::string	_insistingGetInput( std::string message, std::string input ) const;
		std::string	_checkIsSpace( std::string input ) const;

};

#endif
