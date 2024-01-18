#include <iostream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	Bureaucrat gervaso = Bureaucrat("gervaso", 130);
	gervaso.executeForm(*rrf);
	AForm* ppf = someRandomIntern.makeForm("presidential pardono", "Bender");
	ppf = someRandomIntern.makeForm("presidential pardon", "Bender");
	gervaso.executeForm(*ppf);
	AForm* scf = someRandomIntern.makeForm("Shrubbery creation", "Bender");
	gervaso.executeForm(*scf);
}
