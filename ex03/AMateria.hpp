#pragma once

#include <string>

class ICharacter;

class AMateria
{
public:
// Canonical Mandates >:(
	AMateria();
	AMateria(AMateria const & other);
	AMateria(std::string const & type);
	AMateria& operator=(AMateria const & rhs);
	virtual ~AMateria();
//[...]
	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
protected:
	std::string _type;
//[...]
};
