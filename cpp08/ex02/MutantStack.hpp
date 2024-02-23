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
		iterator	begin()
		{
			return (this->c.begin());
		};
		iterator	end()
		{
			return (this->c.end());
		};
};

#endif
