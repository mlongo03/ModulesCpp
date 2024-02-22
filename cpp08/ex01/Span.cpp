#include "Span.hpp"

Span::Span()
{

}

Span::~Span()
{

}

Span::Span(unsigned int N)
{
	size = N;
}

Span::Span(const Span& toCopy)
{
	*this = toCopy;
}

Span&	Span::operator=(const Span& toCopy)
{
	if (this == &toCopy)
		return *this;
	this->size = toCopy.getSize();
	this->list = toCopy.getList();
	return *this;
}

void	Span::addNumber(int n)
{
	if (this->list.size() == size)
		throw Span::StackAlreadyFull();
	this->list.push_back(n);
}

// void	Span::addNumbers(int n)
// {

// }

int		Span::shortestSpan() const
{

}

int		Span::longestSpan() const
{

}


int	Span::getSize()	const
{
	return this->size;
}

std::list<int>	Span::getList() const
{
	return this->list;
}

const char* Span::StackAlreadyFull::what() const throw()
{
	return "Stack is already full";
}

