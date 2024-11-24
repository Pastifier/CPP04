#pragma once

#include "ICharacter.hpp"
#include "MateriaSource.hpp"

class Character : public ICharacter
{
public:
	Character();
	Character(Character const & other);
	Character(std::string const & name);
	Character& operator=(Character const & rhs);
	~Character();

	std::string const & getName() const;

	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
private:
	std::string _name;
	int _materiaNum;
	AMateria* _slots[4];
	static int _instanceCount;
	static MateriaList* _droppedMaterias;
};
