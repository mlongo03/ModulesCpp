#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PPF", 25, 5), target(target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &toCopy) : AForm("PPF", 25, 5)
{
	*this = toCopy;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &toCopy)
{
	this->target = toCopy.getTarget();
	return (*this);
}

std::string	PresidentialPardonForm::getTarget() const
{
	return this->target;
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	checkPermissions(executor);
	std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

