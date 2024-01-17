#include <iostream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	Bureaucrat alfonso = Bureaucrat("alfonso", 150);
	Bureaucrat dario = Bureaucrat("dario", 1);
	PresidentialPardonForm PPF = PresidentialPardonForm("ezio");
	RobotomyRequestForm RRF = RobotomyRequestForm("robot");
	ShrubberyCreationForm SCF = ShrubberyCreationForm("Shrubbery");
	alfonso.executeForm(PPF);
	dario.executeForm(PPF);
	alfonso.executeForm(RRF);
	dario.executeForm(RRF);
	alfonso.executeForm(SCF);
	dario.executeForm(SCF);
	try
	{
		PPF.execute(alfonso);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		PPF.beSigned(dario);
		PPF.execute(dario);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


}
