#include "RPN.hpp"


RPN::RPN()
{
}

RPN::RPN(const RPN& toCopy)
{
	*this = toCopy;
}

RPN::~RPN()
{
}

RPN&	RPN::operator=(const RPN& toCopy)
{
	if (this == &toCopy)
		return *this;
	return *this;
}

void	RPN::calculate_RPN(std::string& expression)
{
	int num1;
	int num2;

	for (std::string::iterator it = expression.begin(); it != expression.end(); it++)
	{
		if (std::isdigit(*it))
			stack.push(*it - 48);
		else if (*it == '+' || *it == '/' || *it == '*' || *it == '-')
		{
			num2 = stack.top();
			// num1 = //penultimo numero dello stack
			switch (*it)
			{
			case '+':
				break;
			case '-':
				break;
			case '/':
				break;
			case '*':
				break;
			}
		}
		else
		{
			std::cout << "Error" << std::endl;
			return ;
		}
	}
}
