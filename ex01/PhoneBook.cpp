#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook(void) : _count(0), _next(0) { return ; }

PhoneBook::~PhoneBook(void) { return ; }

void	PhoneBook::addContact(Contact const &contact)
{
	this->_contacts[this->_next] = contact;
	this->_next = (this->_next + 1) % PhoneBook::_maxContacts;
	if (this->_count < PhoneBook::_maxContacts)
		this->_count++;
}

int		PhoneBook::getCount(void) const { return (this->_count); }

Contact const	&PhoneBook::getContact(int index) const { return (this->_contacts[index]); }

static std::string	truncate(std::string const &str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void	PhoneBook::displayContacts(void) const
{
	std::cout << std::setw(10) << "Index" << "|"
		<< std::setw(10) << "First Name" << "|"
		<< std::setw(10) << "Last Name" << "|"
		<< std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < this->_count; ++i)
	{
		std::cout << std::setw(10) << i << "|"
			<< std::setw(10) << truncate(this->_contacts[i].getFirstName()) << "|"
			<< std::setw(10) << truncate(this->_contacts[i].getLastName()) << "|"
			<< std::setw(10) << truncate(this->_contacts[i].getNickname())
			<< std::endl;
	}
}
