#include <string>
#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria *materias[4];
public:
	MateriaSource();
	~MateriaSource();
	void learnMateria(AMateria* m);
	AMateria* createMateria(std::string const & type);
};
