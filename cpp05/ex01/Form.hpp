#ifndef Form_HPP
#define Form_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	name;
		const int			gradeSign;
		const int			gradeExec;
		bool				isSigned;

	public:
		Form(std::string name, int gradeSign, int gradeExec);
		~Form();
		Form(const Form &toCopy);
		Form& operator=(const Form &toCopy);
		std::string	getName() const;
		int			getGradeSign() const;
		int			getGradeExec() const;
		bool		getIsSigned() const;
		void		beSigned(Bureaucrat& obj);

	public:
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream&	operator<<(std::ostream& os, const Form& obj);
#endif
