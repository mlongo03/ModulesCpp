#ifndef Span_HPP
#define Span_HPP

#include <vector>
#include <string>
#include <iostream>

class Span
{
	private:
		std::vector<int>	vector;
		int				size;
		int	getSize()	const;
		std::vector<int>	getvector() const;
	public:
		Span();
		Span(unsigned int n);
		Span(const Span& toCopy);
		~Span();
		Span&	operator=(const Span& toCopy);
		void	addNumber(int n);
		int		shortestSpan();
		int		longestSpan();
		template <typename Iterator>
		void	addNumbers(Iterator begin, Iterator end);
	public:
		class StackAlreadyFull : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class NoSpanFoundable : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

template <typename Iterator>
void	Span::addNumbers(Iterator begin, Iterator end)
{
	for(; begin != end; begin++)
		addNumber(*begin);
}

#endif
