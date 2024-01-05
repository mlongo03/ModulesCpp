#ifndef Animal_HPP
#define Animal_HPP
#include <string>

class Animal
{
protected:
	std::string type;
public:
	Animal( void );
	Animal(const Animal &toCopy);
	virtual ~Animal();
	Animal& operator=(const Animal &toCopy);
	std::string		getType( void ) const;
	void			setType( std::string type );
	virtual void	makeSound() const;
};

#endif
