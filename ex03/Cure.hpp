#pragma once

#include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure();
	~Cure();
	Cure(Cure const & other);
	Cure& operator=(Cure const & rhs);
	AMateria* clone() const;
	void use(ICharacter& target);
};
