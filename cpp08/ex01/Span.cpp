#include "Span.hpp"
#include <algorithm>
#include <limits>
#include <numeric>

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
	this->vector = toCopy.getvector();
	return *this;
}

void	Span::addNumber(int n)
{
	if (this->vector.size() == (long unsigned int)size)
		throw Span::StackAlreadyFull();
	this->vector.push_back(n);
}


int		Span::shortestSpan()
{
	std::vector<int> orderedvector = vector;

	if (vector.size() < 2)
		throw Span::NoSpanFoundable();
	std::sort(orderedvector.begin(), orderedvector.end());
	std::adjacent_difference(orderedvector.begin(), orderedvector.end(), orderedvector.begin());
	return (*std::min_element(orderedvector.begin()++, orderedvector.end()));
}

int		Span::longestSpan()
{
	if (vector.size() < 2)
		throw Span::NoSpanFoundable();
	return *std::max_element(vector.begin() , vector.end()) - *std::min_element(vector.begin(), vector.end());
}


int	Span::getSize()	const
{
	return this->size;
}

std::vector<int>	Span::getvector() const
{
	return this->vector;
}

const char* Span::StackAlreadyFull::what() const throw()
{
	return "Stack is already full";
}

const char* Span::NoSpanFoundable::what() const throw()
{
	return "No span can be found";
}

