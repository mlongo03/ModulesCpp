#include <iostream>
#include <cctype>
#include <string>

int main(int argc, char **argv)
{
	int j;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 0; i < argc - 1; i++)
		{
			j = 0;
			while (argv[i + 1][j])
			{
				argv[i + 1][j] = std::toupper(argv[i + 1][j]);
				j++;
			}
			std::cout << argv[i + 1];
		}
	}
	std::cout << std::endl;
	return 0;
}
