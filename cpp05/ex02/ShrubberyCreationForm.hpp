#ifndef ShrubberyCreationForm_HPP
#define ShrubberyCreationForm_HPP

#include <string>
#include <iostream>
#include <fstream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
	private:
		std::string	target;
	public:
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &toCopy);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm &toCopy);
		std::string	getTarget() const;
		void		execute(Bureaucrat const & executor) const;
};

#endif
