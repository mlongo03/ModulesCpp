#ifndef Brain_HPP
#define Brain_HPP

#include <string>
#include "Brain.hpp"

class Brain
{
private:
	std::string ideas[100];
public:
	Brain( void );
	~Brain();
	Brain(const Brain &toCopy);
	Brain& operator=(const Brain &toCopy);
	void	setIdea(int idx, std::string idea);
	std::string getIdea(int idx) const;
};

#endif
