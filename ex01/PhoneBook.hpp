#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);

		void	addContact(Contact const &contact);
		void	displayContacts(void) const;

		int		getCount(void) const;
		Contact const	&getContact(int index) const;

	private:
		static int const	_maxContacts = 8;

		Contact		_contacts[_maxContacts];
		int			_count;
		int			_next;
};

#endif
