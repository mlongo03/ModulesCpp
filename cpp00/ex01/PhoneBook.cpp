#include <iostream>
#include <cctype>
#include <string>
#include <iomanip>
#include <sstream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->savedContacts = 0;
	this->oldest = 0;
}

void PhoneBook::ADD()
{
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

	while (1)
	{
		std::cout << "Enter the first name of the contact you want to add: ";
		std::getline(std::cin, firstName);
		std::cout << "Enter the last name of the contact you want to add: ";
		std::getline(std::cin, lastName);
		std::cout << "Enter the nickname of the contact you want to add: ";
		std::getline(std::cin, nickname);
		std::cout << "Enter the phone number of the contact you want to add: ";
		std::getline(std::cin, phoneNumber);
		std::cout << "Enter the darkest secret of the contact you want to add: ";
		std::getline(std::cin, darkestSecret);
		if (!firstName.empty() && !lastName.empty() && !nickname.empty() && !phoneNumber.empty() && !darkestSecret.empty())
			break ;
		std::cout << "fields must not be empty " << std::endl;
	}
	Contact contact = Contact(firstName, lastName, nickname, phoneNumber, darkestSecret);
	if (this->savedContacts != 8)
	{
		this->contacts[this->savedContacts] = contact;
		savedContacts++;
	}
	else
	{
		this->contacts[this->oldest] = contact;
		if (this->oldest + 1 == 8)
			this->oldest = 0;
		else
			this->oldest++;
	}
}

void PhoneBook::SEARCH()
{
	std::string input;

	if (this->savedContacts == 0)
	{
		std::cout << "🤷 Phonebook is empty. Please add contacts first 🤷" << std::endl;
		return;
	}
	printColumns();
	std::cout << "Enter the index of the contact you want to display: ";
	std::getline(std::cin, input);
	if (input.length() > 1 || input[0] - 48 >= savedContacts || input[0] - 48 < 0)
	{
		std::cout << "❌ Invalid index. Contact not found ❌" << std::endl;
		return ;
	}
	else
	{
		int index = input[0] - 48;
		std::cout << "Contact Information:" << std::endl;
		std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
		std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
		std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
		std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
		std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
	}

}

void PhoneBook::printColumns()
{
	for (int i = 0; i < this->savedContacts; i++)
	{
		std::stringstream ss;
		ss << i;
		std::string strNumber = ss.str();
		printColumn(strNumber);
		std::cout << "|";
		printColumn(this->contacts[i].getFirstName());
		std::cout << "|";
		printColumn(this->contacts[i].getLastName());
		std::cout << "|";
		printColumn(this->contacts[i].getNickname());
		std::cout << "|";
		std::cout << std::endl;
	}
}

void PhoneBook::printColumn(std::string str)
{
	if (str.size() > 10)
		std::cout << str.substr(0, 9) << ".";
	else
		std::cout << std::setw(10) << str;
}
