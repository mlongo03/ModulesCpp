#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("SCF", 145, 137), target(target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &toCopy) : AForm("SCF", 145, 137)
{
	*this = toCopy;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &toCopy)
{
	this->target = toCopy.getTarget();
	return (*this);
}

std::string	ShrubberyCreationForm::getTarget() const
{
	return this->target;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	checkPermissions(executor);
	std::string outfilename = target + "_shrubbery";
	std::ofstream file(outfilename.c_str());
	if (file.is_open())
	{
		file << "                      ___"                     << std::endl;
		file << "                _,-'\"\"   \"\"\"\"`--."       << std::endl;
		file << "             ,-'          __,,-- \\"           << std::endl;
		file << "           ,\'    __,--\"\"\"\"dF      )"      << std::endl;
		file << "          /   .-\"Hb_,--\"\"dF      /"         << std::endl;
		file << "        ,\'       _Hb ___dF\"-._,-'"           << std::endl;
		file << "      ,'      _,-\"\"\"\"   \"\"--..__"        << std::endl;
		file << "     (     ,-'                  `."            << std::endl;
		file << "      `._,'     _   _             ;"           << std::endl;
		file << "       ,'     ,' `-'Hb-.___..._,-'"            << std::endl;
		file << "       \\    ,'\"Hb.-\'HH`-.dHF\""             << std::endl;
		file << "        `--\'   \"Hb  HH  dF\""                << std::endl;
		file << "                \"Hb HH dF"                    << std::endl;
		file << "                 \"HbHHdF"                     << std::endl;
		file << "                  |HHHF"                       << std::endl;
		file << "                  |HHH|"                       << std::endl;
		file << "                  |HHH|"                       << std::endl;
		file << "                  |HHH|"                       << std::endl;
		file << "                  |HHH|"                       << std::endl;
		file << "                  dHHHb"                       << std::endl;
		file << "                .dFd|bHb."                     << std::endl;
		file << "              .dHFdH|HbTHb."                   << std::endl;
		file << "           .dHFdHHFdHH|HHhoHHb."               << std::endl;
		file << "##########################################"    << std::endl;
		file.close();
	}
	else
	{
		std::cerr << "Unable to open the file for writing.\n";
	}
}

