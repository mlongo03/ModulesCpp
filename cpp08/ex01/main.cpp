#include "Span.hpp"
#include <vector>
#include <list>
#include <stdlib.h>

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	try
	{
		sp.addNumber(11);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;


	std::vector<int> vectortest;
	int n = 20;

	Span sp1 = Span(n);

	try
	{
		std::cout << sp1.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < n; i++)
	{
		vectortest.push_back(rand() % n);
		std::cout << " " << vectortest.back();
	}
	std::cout << std::endl;

	sp1.addNumbers(vectortest.begin(), vectortest.end());

	std::cout << sp1.shortestSpan() << std::endl;
	std::cout << sp1.longestSpan() << std::endl;

	return 0;
}
