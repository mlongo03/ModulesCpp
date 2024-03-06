#ifndef PmergeMe_HPP
#define PmergeMe_HPP

#include <iostream>
#include <vector>
#include <list>

class PmergeMe
{
	private:
		std::list<int> stack_list;
		std::vector<int> stack_vector;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& toCopy);
		~PmergeMe();
		PmergeMe&			operator=(const PmergeMe& toCopy);
		std::list<int>		get_list() const;
		std::vector<int>	get_vector() const;
		void				check_arguments(char **argv);
		void				load_vector(char **argv);
		void				load_list(char **argv);
		void				sort_list();
		void				sort_vector();

	public:
		class NegativeNumber : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class NotAnInteger : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class HasDuplicated : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif
