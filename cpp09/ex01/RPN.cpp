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

void	RPN::calculate_RPN(std::string expression)
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
			stack.pop();
			num1 = stack.top();
			stack.pop();
			switch (*it)
			{
				case '+':
					stack.push(num1 + num2);
					break;
				case '-':
					stack.push(num1 - num2);
					break;
				case '/':
					stack.push(num1 / num2);
					break;
				case '*':
					stack.push(num1 * num2);
					break;
			}
		}
		else if (!std::isspace(*it))
		{
			std::cout << "Error" << std::endl;
			return ;
		}
	}
	std::cout << stack.top() << std::endl;
}
