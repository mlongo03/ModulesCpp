#include "Intern.hpp"
#include <iostream>
#include <cctype>
#include <string>

Intern::Intern()
{
}

Intern::~Intern()
{
}

Intern::Intern(const Intern &toCopy)
{
	*this = toCopy;
}

Intern& Intern::operator=(const Intern &toCopy)
{
	if (this == &toCopy)
		return *this;
	return (*this);
}

std::string toLowerCase(const std::string& input)
{
	std::string result = input;

	for (std::string::iterator it = result.begin(); it != result.end(); ++it)
		*it = std::tolower(*it);
	return result;
}

AForm*	Intern::makeForm(std::string formName, std::string target)
{
	AForm* result = 0;
	formName = toLowerCase(formName);
	if (formName != "shrubbery creation" && formName != "robotomy request" && formName != "presidential pardon")
	{
		std::cout << "this form does not exist" << std::endl;
		return result;
	}
	switch (formName[0])
	{
	case 's':
		result = new ShrubberyCreationForm(target);
		break;

	case 'r':
		result = new RobotomyRequestForm(target);
		break;

	case 'p':
		result = new PresidentialPardonForm(target);
		break;
	default:
		break;
	}
	std::cout << "Intern created " << *result << std::endl;
	return result;

}

