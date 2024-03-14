#ifndef PmergeMe_HPP
#define PmergeMe_HPP

#include <iostream>
#include <vector>
#include <list>
#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define CYAN "\033[1;36m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define PURPLE "\033[1;35m"
#define WHITE "\033[1;37m"
#define GRAY "\033[1;30m"
#define RESET "\033[0m"

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
		void				sort_deque();
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
