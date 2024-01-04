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
	std::string		getType( void ) const;
	void			setType( std::string type );
	virtual void	makeSound() const=0;
};

#endif
