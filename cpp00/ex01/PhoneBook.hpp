#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "main.h"

class PhoneBook
{
public:
	PhoneBook();
	void ADD(Contact contact);
	Contact SEARCH(Contact contact);
	void EXIT();

private:
	Contact *contacts;
};

#endif
