
#include <iostream>
#include <string>

int	main()
{
	std::string string = "HI THIS IS BRAIN";
	std::string* stringPTR = &string;
	std::string& stringREF = string;
	std::cout << "the string address is -> " << &string << std::endl;
	std::cout << "address of the string held by stringPTR is -> " << &stringPTR << std::endl;
	std::cout << "address of the string held by stringREF is -> " << &stringREF << std::endl;
	std::cout << "the string value is -> " << string << std::endl;
	std::cout << "value pointed by stringPTR is -> " << stringPTR << std::endl;
	std::cout << "value pointed by stringREF is -> " << stringREF << std::endl;
}
