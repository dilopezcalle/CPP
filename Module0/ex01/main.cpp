#define RED "\033[0;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[0;33m"
#define RESET "\033[0;0m"

#include <iostream>
#include <sstream>

#include "PhoneBook.hpp"
#include "Contact.hpp"

static std::string	str_to_upper(std::string str);
static Contact		get_contact_data(void);

int	main(void)
{
	std::string	command;
	PhoneBook	phone_book;

	while (1)
	{
		// Print welcome message
		std::cout << GREEN << "\nIntroduce un comando válido:\n" << RESET << std::endl;
		if (phone_book.getNumContacts() < 8)
			std::cout << "- " << YELLOW << "ADD\t\t" << RESET << "(Agregar contacto a la agenda)" << std::endl;
		std::cout << "- " << YELLOW << "SEARCH\t" << RESET << "(Buscar un contacto de la agenda)" << std::endl;
		std::cout << "- " << YELLOW << "EXIT" << RESET << "\t\t(Salir del programa)" << std::endl;
		std::cout << std::endl << ">> ";

		// Get user's input
		std::getline(std::cin, command);
		std::cout << std::endl;
		command = str_to_upper(command);

		// Check user's input
		if (command.compare("ADD") == 0 && phone_book.getNumContacts() < 8)
			phone_book.addContact(get_contact_data());
		else if (command.compare("SEARCH") == 0)
		{
			phone_book.showContacts();
			command.clear();
			std::cout << "Index del contacto >> ";
			std::getline(std::cin, command);
			std::cout << std::endl;
			if (phone_book.showContactByIndex(command))
				std::cout << RED << "Index inválido" << RESET << std::endl;
		}
		else if (command.compare("EXIT") == 0)
			break;
	}
	return (0);
}

static std::string	str_to_upper(std::string str)
{
	std::string	result = str;

	int n = str.length();
	for (int i = 0; i < n; i++)
		result[i] = (char)toupper(str[i]);
	return (result);
}

static Contact	get_contact_data(void)
{
	size_t		i;
	int			phone;
	Contact 	contact;
	std::string	first_name;
	std::string	last_name;
	std::string	nick_name;
	std::string	phone_number;
	std::string	darkest_secret;

	// Get data
	std::cout << "Nombre: ";
	std::getline(std::cin, first_name);
	std::cout << "Apellido: ";
	std::getline(std::cin, last_name);
	std::cout << "Apodo: ";
	std::getline(std::cin, nick_name);
	std::cout << "Teléfono: ";
	std::getline(std::cin, phone_number);
	std::cout << "Secreto: ";
	std::getline(std::cin, darkest_secret);
	std::cout << std::endl;

	// Check phone number is number
	for (i = 0; std::isdigit((char)phone_number[i]) != 0; i++);

	// Create contact object
	if (i != phone_number.length() || i > 10 || first_name.empty() || last_name.empty() || \
		nick_name.empty() || phone_number.empty() || darkest_secret.empty())
	{
		std::cout << RED << "Alguno de los datos NO es válido" << RESET << std::endl;
		return (contact);
	}
	std::istringstream(phone_number) >> phone;
	return (Contact(first_name, last_name, nick_name, phone, darkest_secret));
}
