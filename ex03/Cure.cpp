#include "Cure.hpp"
#include "ICharacter.hpp"
#include <iostream>

#define PRINT(X) std::cout << X << std::endl

Cure::Cure() : AMateria("cure") {}
Cure::Cure(Cure const & other) : AMateria(other) {}
Cure::~Cure() {}

Cure& Cure::operator=(Cure const & rhs) {
	if (this != &rhs)
		AMateria::operator=(rhs);
	return *this;
}

AMateria* Cure::clone() const { return new Cure(*this); }

void Cure::use(ICharacter& target) {
	PRINT("* heals " << target.getName() << "\'s wounds *");
}
