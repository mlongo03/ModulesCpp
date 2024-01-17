#ifndef RobotomyRequestForm_HPP
#define RobotomyRequestForm_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
	private:
		std::string	target;
	public:
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &toCopy);
		RobotomyRequestForm& operator=(const RobotomyRequestForm &toCopy);
		std::string	getTarget() const;
		void		execute(Bureaucrat const & executor) const;
};

#endif
