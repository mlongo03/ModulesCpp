#include "easyfind.hpp"
#include <vector>
#include <list>

int main()
{
	std::vector<int> vector;
	std::list<int> list;
	vector.push_back(10);
	vector.push_back(20);
	vector.push_back(30);
	list.push_back(10);
	list.push_back(20);
	list.push_back(30);
	try
	{
		easyfind(vector, 10);
		easyfind(vector, 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		easyfind(list, 10);
		easyfind(list, 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}
