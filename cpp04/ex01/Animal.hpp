#ifndef Animal_HPP
#define Animal_HPP
#include <string>

class Animal
{
protected:
	std::string type;
public:
	Animal( void );
	virtual ~Animal();
	Animal(const Animal &toCopy);
	Animal& operator=(const Animal &toCopy);
	std::string		getType( void ) const;
	void			setType( std::string type );
	virtual void	makeSound() const;
};

#endif
