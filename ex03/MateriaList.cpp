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
