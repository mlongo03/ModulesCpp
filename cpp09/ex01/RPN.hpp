#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

class RPN
{
	private:
		std::stack<int> stack;
	public:
		RPN();
		RPN(const RPN& toCopy);
		~RPN();
		RPN&	operator=(const RPN& toCopy);
		void	calculate_RPN(std::string expression);
};

#endif
