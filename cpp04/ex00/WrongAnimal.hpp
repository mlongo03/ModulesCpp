#ifndef WrongAnimal_HPP
#define WrongAnimal_HPP
#include <string>

class WrongAnimal
{
protected:
	std::string type;
public:
	WrongAnimal( void );
	~WrongAnimal();
	WrongAnimal(const WrongAnimal &toCopy);
	WrongAnimal& operator=(const WrongAnimal &toCopy);
	std::string		getType( void ) const;
	void			setType( std::string type );
	void			makeSound() const;
};

#endif
