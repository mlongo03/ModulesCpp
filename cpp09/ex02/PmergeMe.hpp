#ifndef PmergeMe_HPP
#define PmergeMe_HPP

#include <iostream>
#include <vector>
#include <list>

class PmergeMe
{
	private:
		std::vector<int> numbers;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& toCopy);
		~PmergeMe();
		PmergeMe&			operator=(const PmergeMe& toCopy);
		std::vector<int>	get_numbers() const;
		void				check_arguments(char **argv);
		void				load_numbers(char **argv);
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
