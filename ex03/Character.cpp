#include "Character.hpp"
#include "AMateria.hpp"
#include <iostream>

#define PRINT(X) std::cout << X << std::endl

int Character::_referenceCount = 0;
MateriaList* Character::_droppedMaterias = NULL;

Character::Character() : _name("Cloud") {
	for (int i = 0; i < 4; i++) {
		_slots[i] = NULL;
	}
	_materiaNum = 0;
	_referenceCount++;
}

Character::Character(Character const & other) : _name(other.getName()) {
	for (int i = 0; i < 4; i++) {
		if (other._slots[i])
			this->_slots[i] = other._slots[i]->clone();
	}
	this->_materiaNum = other._materiaNum;
	_referenceCount++;
}

Character::Character(std::string const & name) : _name(name) {
	for (int i = 0; i < 4; i++) {
		_slots[i] = NULL;
	}
	_materiaNum = 0;
	_referenceCount++;
}

Character& Character::operator=(Character const & rhs) {
	if (this != &rhs) {
		for (int i = 0; i < 4; i++) {
			delete _slots[i];
			_slots[i] = NULL;
		}
		for (int i = 0; i < rhs._materiaNum; i++) {
			if (rhs._slots[i])
				_slots[i] = rhs._slots[i]->clone();
		}
		this->_name = rhs._name;
		this->_materiaNum = rhs._materiaNum;
	}
	return *this;
}

Character::~Character() {
	for (int i = 0; i < 4; i++)
		delete _slots[i];
	_referenceCount--;
	if (_referenceCount == 0)
		destroyMateriaList(&_droppedMaterias);
}

std::string const& Character::getName() const {
	return _name;
}

void Character::equip(AMateria* m) {
	if (_materiaNum == 4) {
		PRINT(_name << " has no space in their inventory.");
		return;
	}
	if (m) {
		for (int i = 0; i < 4; i++) {
			if (_slots[i] == NULL) {
				_slots[i] = m;
				_materiaNum++;
				break;
			}
		}
	}
}

void Character::unequip(int idx) {
	if (idx >= 0 && idx < 4 && _slots[idx]) {
		bool alreadyStored = false;
		MateriaList* current = _droppedMaterias;
		while (current) {
			if (current->content == _slots[idx]) {
				alreadyStored = true;
				break;
			}
			current = current->next;
		}
		if (!alreadyStored)
		{
			MateriaList* newNode = new MateriaList;
			newNode->content = _slots[idx];
			newNode->next = _droppedMaterias;
			_droppedMaterias = newNode;
		}
		_slots[idx] = NULL;
		_materiaNum--;
	}
}

void Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx < 4 && _slots[idx]) {
		std::cout << _name << ": ";
		_slots[idx]->use(target);
	}
}
