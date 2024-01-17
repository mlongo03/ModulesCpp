#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RRF", 72, 45), target(target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &toCopy) : AForm("RRF", 72, 45)
{
	*this = toCopy;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &toCopy)
{
	this->target = toCopy.getTarget();
	return (*this);
}

std::string	RobotomyRequestForm::getTarget() const
{
	return this->target;
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	checkPermissions(executor);
	std::cout << target << " zzzzZZzz zzzZZzz ";
	std::srand(std::time(0));
	if (std::rand() % 2 == 0)
		std::cout << target << " has been robotomized" << std::endl;
	else
		std::cout << target << " has not been robotomized" << std::endl;
}

