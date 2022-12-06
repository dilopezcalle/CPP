#include "Contact.hpp"
#include <iostream>
#include <iomanip>

Contact::Contact(std::string first_name, std::string last_name, std::string nick_name, \
				int phone_number, std::string darkest_secret)
{
	this->_index = 0;
	this->_firstName = first_name;
	this->_lastName = last_name;
	this->_nickName = nick_name;
	this->_phoneNumber = phone_number;
	this->_darkestSecret = darkest_secret;
}

Contact::Contact(void)
{
	this->_index = -1;
	return ;
}

Contact::~Contact(void)
{
	return ;
}

int	Contact::showTableContact(void) const
{
	
	std::cout << "|" << std::setw(10) << std::setfill(' ') << this->_index;
	if (this->_firstName.length() > 10)
		std::cout << "|" << this->_firstName.substr(0, 9) << ".";
	else
		std::cout << "|" << std::setw(10) << std::setfill(' ') << this->_firstName;
	if (this->_lastName.length() > 10)
		std::cout << "|" << this->_lastName.substr(0, 9) << ".";
	else
		std::cout << "|" << std::setw(10) << std::setfill(' ') << this->_lastName;
	if (this->_nickName.length() > 10)
		std::cout << "|" << this->_nickName.substr(0, 9) << ".|" <<  std::endl;
	else
		std::cout << "|" << std::setw(10) << std::setfill(' ') << this->_nickName << "|" << std::endl;
	return (0);
}

int	Contact::showContact(void) const
{
	std::cout << "Index:\t\t" << this->_index << std::endl;
	std::cout << "Nombre:\t\t" << this->_firstName << std::endl;
	std::cout << "Apellido:\t" << this->_lastName << std::endl;
	std::cout << "Apodo:\t\t" << this->_nickName << std::endl;
	std::cout << "Teléfono:\t" << this->_phoneNumber << std::endl;
	std::cout << "Secreto:\t" << this->_index << std::endl;
	return (0);
}

int	Contact::getIndex(void) const
{
	return (this->_index);
}

int	Contact::setIndex(int index)
{
	this->_index = index;
	return (0);
}