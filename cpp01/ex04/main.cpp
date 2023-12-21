#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Not enough arguments" << std::endl;
		return (1);
	}

	int			startToFind = 0;
	std::size_t	found;
	std::string	filename = argv[1];
	std::string	outfilename = filename.append(".replace");
	std::string	toFind = argv[2];
	std::string	replace = argv[3];

	std::ifstream inFile(argv[1]);
	if (inFile.is_open())
	{
		std::string line;
		std::ofstream outFile(outfilename.c_str());
		if (outFile.is_open())
		{
			while (getline(inFile, line))
			{
				startToFind = 0;
				while ((found = line.find(toFind, startToFind)) != std::string::npos)
				{
					line.insert(found + toFind.size(), replace);
					line.erase(found, toFind.size());
					startToFind = found + replace.size();
				}
				outFile << line << std::endl;
			}
			outFile.close();
		}
		else
		{
			std::cerr << "Unable to open the file for writing.\n";
			return (1);
		}

		inFile.close();
	}
	else
	{
		std::cerr << "Unable to open the file for reading.\n";
		return (1);
	}
}
