#include <iostream>
#include <string>
#include "Harl.hpp"

Harl::Harl()
{
	return ;
}

Harl::~Harl()
{

}

void	Harl::debug( void )
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error( void )
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain( std::string level )
{
	void (Harl::*levels_ptr[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	if (level != "DEBUG" && level != "INFO" && level != "WARNING" && level != "ERROR")
	{
		std::cout << "not valid level" << std::endl;
		return ;
	}
	switch (level[0])
	{
		case 'D':
			for (int i  = 0; i < 4; i++)
				(this->*levels_ptr[i])();
			break;
		case 'I':
			for (int i  = 1; i < 4; i++)
				(this->*levels_ptr[i])();
			break;
		case 'W':
			for (int i  = 2; i < 4; i++)
				(this->*levels_ptr[i])();
			break;
		case 'E':
			(this->*levels_ptr[3])();
			break;
		default:
			break;
	}
}
