#ifndef MutantStack_HPP
#define MutantStack_HPP

#include <stack>
#include <deque>
#include <string>
#include <iostream>

template<typename T, typename container_type = std::deque<T> >
class MutantStack : public std::stack<T, container_type>
{
	public:
		typedef typename container_type::iterator	iterator;
		MutantStack();
		MutantStack(const MutantStack& toCopy);
		~MutantStack();
		MutantStack&	operator=(const MutantStack& toCopy);
		iterator	begin();
		iterator	end();
};

template<typename T, typename container_type>
MutantStack<T, container_type>::MutantStack() : std::stack<T, container_type>() {}

template<typename T, typename container_type>
MutantStack<T, container_type>::MutantStack(const MutantStack& toCopy) : std::stack<T, container_type>(toCopy) {}

template<typename T, typename container_type>
MutantStack<T, container_type>::~MutantStack() {}

template<typename T, typename container_type>
MutantStack<T, container_type>&	MutantStack<T, container_type>::operator=(const MutantStack<T, container_type>& toCopy)
{
	if (this == &toCopy)
		return *this;
	this->c = toCopy.c;
	return *this;
}

template<typename T, typename container_type>
typename MutantStack<T, container_type>::iterator	MutantStack<T, container_type>::begin()
{
	return (this->c.begin());
};

template<typename T, typename container_type>
typename MutantStack<T, container_type>::iterator	MutantStack<T, container_type>::end()
{
	return (this->c.end());
};

#endif
