#include "Ice.hpp"
#include "ICharacter.hpp"
#include <iostream>

#define PRINT(X) std::cout << X << std::endl

Ice::Ice() : AMateria("ice") {}
Ice::Ice(Ice const & other) : AMateria(other) {}
Ice::~Ice() {}

Ice& Ice::operator=(Ice const & rhs) {
	if (this != &rhs)
		AMateria::operator=(rhs);
	return *this;
}

AMateria* Ice::clone() const { return new Ice(*this); }

void Ice::use(ICharacter& target) {
	PRINT("* shoots an ice bolt at " << target.getName() << " *");
}
