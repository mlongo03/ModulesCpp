#include "main.h"

int main()
{
	std::string command;
	PhoneBook phoneBook = PhoneBook();

	while (command.compare("EXIT"))
	{
		std::cout << "Enter a command: ";
		std::getline(std::cin, command);
		if (!command.compare("ADD"))
			phoneBook.ADD();
		else if (!command.compare("SEARCH"))
			phoneBook.SEARCH();
	}
	return (0);
}
