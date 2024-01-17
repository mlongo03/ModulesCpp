#ifndef AForm_HPP
#define AForm_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	name;
		const int			gradeSign;
		const int			gradeExec;
		bool				isSigned;

	public:
		AForm(std::string name, int gradeSign, int gradeExec);
		virtual ~AForm();
		AForm(const AForm &toCopy);
		AForm& operator=(const AForm &toCopy);
		std::string		getName() const;
		int				getGradeSign() const;
		int				getGradeExec() const;
		bool			getIsSigned() const;
		void			beSigned(Bureaucrat& obj);
		void			checkPermissions(Bureaucrat const & executor) const;
		virtual void	execute(Bureaucrat const & executor) const=0;

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
		class FormAlreadySignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream&	operator<<(std::ostream& os, const AForm& obj);
#endif
