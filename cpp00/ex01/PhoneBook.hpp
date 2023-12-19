#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
public:
	PhoneBook(void);
	void ADD();
	void SEARCH();
	void printColumns();
	void printColumn(std::string str);

private:
	Contact contacts[8];
	int savedContacts;
	int oldest;
};

#endif
