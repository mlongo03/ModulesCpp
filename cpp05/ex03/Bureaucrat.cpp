#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	if (grade > 150)
		throw  Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw  Bureaucrat::GradeTooHighException();
	this->grade = grade;
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &toCopy)
{
	*this = toCopy;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &toCopy)
{
	this->grade = toCopy.getGrade();
	return (*this);
}

std::string Bureaucrat::getName() const
{
	return this->name;
}

int Bureaucrat::getGrade() const
{
	return this->grade;
}

void Bureaucrat::incGrade()
{
	if ((this->grade - 1) < 1)
		throw  Bureaucrat::GradeTooHighException();
	this->grade--;
}

void Bureaucrat::decGrade()
{
	if ((this->grade + 1) > 150)
		throw  Bureaucrat::GradeTooLowException();
	this->grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Error: Grade is higher than 1";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Error: Grade is less than 150";
}

void	Bureaucrat::signForm(AForm& obj)
{
	try
	{
		obj.beSigned(*this);
		std::cout << *this << " signed " << obj << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << *this << " couldn't sign because " << e.what() << std::endl;
	}

}

void	Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		std::cout << *this << " executed " << form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << *this << " did not executed the form because " << e.what() << std::endl;
	}
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return os;
}
