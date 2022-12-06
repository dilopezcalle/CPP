#include <sstream>
#include <iomanip>

#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook()
{
	this->_numContacts = 0;
	return ;
}

PhoneBook::~PhoneBook()
{
	return ;
}

int	PhoneBook::getNumContacts(void) const
{
	return (this->_numContacts);
}

int	PhoneBook::addContact(Contact contact)
{
	if (contact.getIndex() == -1)
		return (0);
	contact.setIndex(this->_numContacts);
	this->_contactList[this->_numContacts] = contact;
	this->_numContacts++;
	return (0);
}

int	PhoneBook::showContacts(void)
{
	std::cout << "*" << std::setw(44) << std::setfill('-') << "*" << std::endl;
	std::cout << "|  INDEX   |  NOMBRE  | APELLIDO |   APODO  |" << std::endl;
	std::cout << "|" << std::setw(44) << std::setfill('-') << "|" << std::endl;
	for (int i = 0; i < this->_numContacts; i++)
		this->_contactList[i].showTableContact();
	std::cout << "*" << std::setw(44) << std::setfill('-') << "*" << std::endl;
	std::cout << std::endl;
	return (0);
}

int	PhoneBook::showContactByIndex(std::string str_index)
{
	size_t	i;
	size_t	index;

	for (i = 0; std::isdigit((char)str_index[i]) != 0; i++);	
	if (i != str_index.length())
		return (1);
	std::istringstream(str_index) >> index;
	if (index >= (size_t)this->_numContacts)
		return (1);
	for (i = 0; i != index; i++);
	this->_contactList[i].showContact();
	return (0);
}