#include "Form.hpp"

Form::Form(std::string name, int gradeSign, int gradeExec) : name(name), gradeSign(gradeSign), gradeExec(gradeExec)
{
	if (gradeSign > 150 || gradeExec > 150)
		throw  Form::GradeTooLowException();
	else if (gradeSign < 1 || gradeSign < 1)
		throw  Form::GradeTooHighException();
	this->isSigned = false;
}

Form::~Form()
{
}

Form::Form(const Form &toCopy) : name(toCopy.getName()), gradeSign(toCopy.getGradeSign()), gradeExec(toCopy.getGradeExec())
{
	*this = toCopy;
}

Form& Form::operator=(const Form &toCopy)
{
	this->isSigned = toCopy.isSigned;
	return (*this);
}

std::string Form::getName() const
{
	return this->name;
}

int Form::getGradeSign() const
{
	return this->gradeSign;
}

int Form::getGradeExec() const
{
	return this->gradeExec;
}

bool	Form::getIsSigned() const
{
	return this->isSigned;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "grade is too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "grade is too low";
}

std::ostream&	operator<<(std::ostream& os, const Form& obj)
{
	os << obj.getName() << ", Form grade to Sign " << obj.getGradeSign() << ", grade to Execute " << obj.getGradeExec() << ((obj.getIsSigned()) ? " is signed" : " is not signed yet");
	return os;
}

void	Form::beSigned(Bureaucrat& obj)
{
	if (obj.getGrade() > this->gradeSign)
		throw Form::GradeTooLowException();
	this->isSigned = true;
}
