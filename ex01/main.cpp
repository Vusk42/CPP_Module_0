#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

static bool	promptField(std::string const &label, std::string &out)
{
	std::cout << label << ": ";
	if (!std::getline(std::cin, out))
		return (false);
	while (out.empty())
	{
		std::cout << "This field can't be empty." << std::endl;
		std::cout << label << ": ";
		if (!std::getline(std::cin, out))
			return (false);
	}
	return (true);
}

static bool	addContact(PhoneBook &phonebook)
{
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	phoneNumber;
	std::string	darkestSecret;
	Contact		contact;

	if (!promptField("First name", firstName)
		|| !promptField("Last name", lastName)
		|| !promptField("Nickname", nickname)
		|| !promptField("Phone number", phoneNumber)
		|| !promptField("Darkest secret", darkestSecret))
		return (false);
	contact.set(firstName, lastName, nickname, phoneNumber, darkestSecret);
	phonebook.addContact(contact);
	std::cout << "Contact added." << std::endl;
	return (true);
}

static void	searchContact(PhoneBook const &phonebook)
{
	std::string	input;
	int			index;

	if (phonebook.getCount() == 0)
	{
		std::cout << "The phonebook is empty." << std::endl;
		return ;
	}
	phonebook.displayContacts();
	std::cout << "Index: ";
	if (!std::getline(std::cin, input))
		return ;
	if (input.empty() || input.find_first_not_of("0123456789") != std::string::npos)
	{
		std::cout << "Invalid index." << std::endl;
		return ;
	}
	index = std::atoi(input.c_str());
	if (index < 0 || index >= phonebook.getCount())
	{
		std::cout << "Index out of range." << std::endl;
		return ;
	}
	Contact const	&c = phonebook.getContact(index);
	std::cout << "First name    : " << c.getFirstName() << std::endl;
	std::cout << "Last name     : " << c.getLastName() << std::endl;
	std::cout << "Nickname      : " << c.getNickname() << std::endl;
	std::cout << "Phone number  : " << c.getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << c.getDarkestSecret() << std::endl;
}

int	main(void)
{
	PhoneBook	phonebook;
	std::string	command;

	while (true)
	{
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, command))
			break ;
		if (command == "ADD")
		{
			if (!addContact(phonebook))
				break ;
		}
		else if (command == "SEARCH")
			searchContact(phonebook);
		else if (command == "EXIT")
			break ;
	}
	return (0);
}
