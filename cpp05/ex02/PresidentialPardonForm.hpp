#ifndef PresidentialPardonForm_HPP
#define PresidentialPardonForm_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
	private:
		std::string	target;
	public:
		PresidentialPardonForm(std::string target);
		~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &toCopy);
		PresidentialPardonForm& operator=(const PresidentialPardonForm &toCopy);
		std::string	getTarget() const;
		void		execute(Bureaucrat const & executor) const;
};

#endif
