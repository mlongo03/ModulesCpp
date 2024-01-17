#ifndef Intern_HPP
#define Intern_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Bureaucrat;

class Intern
{
	public:
		Intern();
		~Intern();
		Intern(const Intern &toCopy);
		Intern& operator=(const Intern &toCopy);
		AForm*	makeForm(std::string formName, std::string target);
};

#endif
