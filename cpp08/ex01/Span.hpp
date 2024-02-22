#ifndef Span_HPP
#define Span_HPP

#include <list>
#include <string>
#include <iostream>

class Span
{
	private:
		std::list<int>	list;
		int				size;
		int	getSize()	const;
		std::list<int>	getList() const;
	public:
		Span();
		Span(unsigned int n);
		Span(const Span& toCopy);
		~Span();
		Span&	operator=(const Span& toCopy);
		void	addNumber(int n);
		// void	addNumbers(int n);
		int		shortestSpan() const;
		int		longestSpan() const;
	public:
		class StackAlreadyFull : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif
