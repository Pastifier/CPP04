#pragma once

#include "IMateriaSource.hpp"
#include "MateriaList.hpp"

// Better, and more efficient, to use a dynamic hashmap for this, but
// it's overkill for this project.



class MateriaSource : public IMateriaSource
{
public:
	MateriaSource();
	MateriaSource(MateriaSource const & other);
	MateriaSource& operator=(MateriaSource const & rhs);
	~MateriaSource();
	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const & type);
private:
	MateriaList* _learnedMateria;
};
