#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

#define PRINT(X) std::cout << X << std::endl

AMateria::AMateria() : _type ("(null)") {}
AMateria::~AMateria() {}
AMateria::AMateria(AMateria const & other) : _type(other.getType()) {}
AMateria::AMateria(std::string const & type) :	_type(type) {}

AMateria& AMateria::operator=(AMateria const & rhs) {
	this->_type = rhs.getType();
	return *this;
}

std::string const &AMateria::getType() const { return _type; }

void AMateria::use(ICharacter& target) {
	PRINT(_type << " was used on " << target.getName() << "... What does that even mean..?");
}
