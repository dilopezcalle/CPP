#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>

#include "Contact.hpp"

class PhoneBook
{
public:
	// ===== Constructor =====
	PhoneBook(void);

	// ===== Destructor =====
	~PhoneBook(void);

	// ===== Getters =====
	int		getNumContacts(void) const;

	// ===== Methods =====
	int	addContact(Contact contact);
	int	showContacts(void);
	int	showContactByIndex(std::string str_index);

private:
	// ===== Variables =====
	int		_numContacts;
	Contact	_contactList[8];	// Max contacts: 8
};

#endif