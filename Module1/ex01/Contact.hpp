#ifndef CONTACT_H
# define CONTACT_H

# include <iostream>

class Contact
{
public:
	// ===== Constructor =====
	Contact(void);
	Contact(std::string first_name, std::string last_name, std::string nick_name, \
			int phone_number, std::string darkest_secret);

	// ===== Destructor =====
	~Contact(void);

	// ===== Getters =====
	int	getIndex(void);

	// ===== Setters =====
	int	setIndex(int index);

	// ===== Methods =====
	int	showContact(void);

private:
	// ===== Variables =====
	int			_index;
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickName;
	int			_phoneNumber;
	std::string	_darkestSecret;	
};

#endif