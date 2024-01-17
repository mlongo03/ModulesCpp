#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat alfonso = Bureaucrat("alfonso", 160);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat alberto = Bureaucrat("alberto", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat enzo = Bureaucrat("enzo", 150);
		std::cout << enzo << std::endl;
		enzo.decGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat lorenzo = Bureaucrat("lorenzo", 1);
		std::cout << lorenzo << std::endl;
		lorenzo.incGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


}
