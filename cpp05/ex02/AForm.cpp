#include "AForm.hpp"

AForm::AForm(std::string name, int gradeSign, int gradeExec) : name(name), gradeSign(gradeSign), gradeExec(gradeExec)
{
	if (gradeSign > 150 || gradeExec > 150)
		throw  AForm::GradeTooLowException();
	else if (gradeSign < 1 || gradeSign < 1)
		throw  AForm::GradeTooHighException();
	this->isSigned = false;
}

AForm::~AForm()
{
}

AForm::AForm(const AForm &toCopy) : name(toCopy.getName()), gradeSign(toCopy.getGradeSign()), gradeExec(toCopy.getGradeExec())
{
	*this = toCopy;
}

AForm& AForm::operator=(const AForm &toCopy)
{
	this->isSigned = toCopy.isSigned;
	return (*this);
}

std::string AForm::getName() const
{
	return this->name;
}

int AForm::getGradeSign() const
{
	return this->gradeSign;
}

int AForm::getGradeExec() const
{
	return this->gradeExec;
}

bool	AForm::getIsSigned() const
{
	return this->isSigned;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "grade is too low";
}

const char* AForm::FormAlreadySignedException::what() const throw()
{
	return "form is already signed";
}

void	AForm::beSigned(Bureaucrat& obj)
{
	if (obj.getGrade() > this->gradeSign)
		throw AForm::GradeTooLowException();
	this->isSigned = true;
}

std::ostream&	operator<<(std::ostream& os, const AForm& obj)
{
	os << obj.getName() << ", AForm grade to Sign " << obj.getGradeSign() << ", grade to Execute " << obj.getGradeExec() << ((obj.getIsSigned()) ? " is signed" : " is not signed yet");
	return os;
}

void	AForm::checkPermissions(Bureaucrat const & executor) const
{
	if (this->isSigned)
		throw AForm::FormAlreadySignedException();
	else if (executor.getGrade() > this->gradeExec)
		throw AForm::GradeTooLowException();
}
