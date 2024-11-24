#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include "MateriaList.hpp"
#include <iostream>

#define PRINT(X) std::cout << X << std::endl;

MateriaSource::MateriaSource() : _learnedMateria(NULL) {}

MateriaSource::MateriaSource(MateriaSource const & other) : _learnedMateria(NULL) {
	MateriaList* current = other._learnedMateria;

	while (current) {
		if (current->content)
			this->learnMateria(current->content->clone());
		current = current->next;
	}
}

MateriaSource& MateriaSource::operator=(MateriaSource const & rhs) {
	if (this != &rhs) {
		destroyMateriaList(&this->_learnedMateria);

		MateriaList* srcCurrent = rhs._learnedMateria;
		while (srcCurrent) {
			if (srcCurrent->content) {
				this->learnMateria(srcCurrent->content->clone());
			}
			srcCurrent = srcCurrent->next;
		}
	}
	return *this;
}


void MateriaSource::learnMateria(AMateria* materia) {
	if (!materia) return;

	MateriaList* current = _learnedMateria;
	while (current) {
		if (current->content == materia) return;
		current = current->next;
	}

	MateriaList* newNode = new MateriaList;
	newNode->content = materia;
	newNode->next = _learnedMateria;
	_learnedMateria = newNode;
}


AMateria* MateriaSource::createMateria(std::string const & type) {
	MateriaList* current = _learnedMateria;

	while (current) {
		if (current->content && current->content->getType() == type) {
			return current->content->clone();
		}
		current = current->next;
	}
	PRINT("Materia of type `" << type << "` not yet learned.");

	return NULL;
}

MateriaSource::~MateriaSource() {
	destroyMateriaList(&this->_learnedMateria);
}
