#include "MateriaList.hpp"

void destroyMateriaList(MateriaList** list) {
	MateriaList* current = *list;
		while (current) {
			MateriaList* next = current->next;
			delete current->content;
			delete current;
			current = next;
		}
		*list = NULL;
}

bool materiaExists(MateriaList* node, AMateria* materia) {
	while (node) {
		if (node->content && node->content == materia)
			return true;
		node = node->next;
	}
	return false;
}