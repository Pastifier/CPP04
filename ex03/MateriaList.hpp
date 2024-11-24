#pragma once

#include "AMateria.hpp"

typedef struct s_MateriaList
{
	AMateria* content;
	struct s_MateriaList* next;
}	MateriaList;

void destroyMateriaList(MateriaList** list);