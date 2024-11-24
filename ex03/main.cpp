#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include <iostream>

void basicTests() {
    std::cout << "===== BASIC TESTS =====" << std::endl;

    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");
    AMateria* tmp;

    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");

    me->use(0, *bob); 
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;

    std::cout << "===== END OF BASIC TESTS =====\n" << std::endl;
}

void inventoryTests() {
    std::cout << "===== INVENTORY TESTS =====" << std::endl;

    ICharacter* me = new Character("me");

    me->equip(new Ice());
    me->equip(new Cure());
    me->equip(new Ice());
    me->equip(new Cure());

    ICharacter* bob = new Character("bob");

    AMateria* extraMateria = new Ice();
    me->equip(extraMateria); 

    me->use(0, *bob); 
    me->use(1, *bob); 
    me->use(2, *bob); 
    me->use(3, *bob); 

    me->unequip(0);
    delete extraMateria;

    std::cout << "after unequip, using bob" << std::endl;
    me->use(1, *bob);
    std::cout << "nothing shouldve happened" << std::endl;
    

    AMateria* newCure = new Cure();
    me->equip(newCure);
    me->use(1, *bob);

    delete bob;
    delete me;

    std::cout << "===== END OF INVENTORY TESTS =====\n" << std::endl;
}

void deepCopyTests() {
    std::cout << "===== DEEP COPY TESTS =====" << std::endl;

    ICharacter* original = new Character("original");
    original->equip(new Ice());
    original->equip(new Cure());


    ICharacter* bob = new Character("bob");

    std::cout << "Original Character uses Materias:" << std::endl;
    original->use(0, *bob); 
    original->use(1, *bob); 

    std::cout << "Copy Character uses Materias:" << std::endl;

    original->unequip(0);
    original->equip(new Ice());

    std::cout << "After modification - Original uses Materias:" << std::endl;
    original->use(0, *bob); 
    original->use(1, *bob); 


    delete bob;
    delete original;

    std::cout << "===== END OF DEEP COPY TESTS =====\n" << std::endl;
}

void sourceTests() {
    std::cout << "===== MATERIA SOURCE TESTS =====" << std::endl;

    IMateriaSource* src = new MateriaSource();

    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    AMateria* ice1 = src->createMateria("ice");
    AMateria* cure1 = src->createMateria("cure");

    if (ice1) std::cout << "Successfully created ice Materia" << std::endl;
    if (cure1) std::cout << "Successfully created cure Materia" << std::endl;

    AMateria* unknown = src->createMateria("fire");
    if (!unknown) std::cout << "Unknown Materia could not be created" << std::endl;

    src->learnMateria(new Ice());  
    src->learnMateria(new Cure()); 
    src->learnMateria(new Ice());  

    delete ice1;
    delete cure1;
    delete src;

    std::cout << "===== END OF MATERIA SOURCE TESTS =====\n" << std::endl;
}

void randomTests()
{
    std::cout << "===== randomTests TESTS =====" << std::endl;

	AMateria *cure = new Cure();
	std::cout << cure->getType() << "\n\n\n";

	AMateria *ice = new Ice();
	std::cout << ice->getType() << "\n\n\n";

	
	AMateria *cureClone = cure->clone();
	std::cout << cureClone->getType() << "\n";
	delete cureClone;
	std::cout << "\n\n";

	
	AMateria *iceClone = ice->clone();
	std::cout << iceClone->getType() << "\n";
	delete iceClone;
	std::cout << "\n\n";
	
	{
		Cure A;
		std::cout << A.getType();
		std::cout << "\n\n";
		
		Cure C(A);
		std::cout << C.getType() + "\n";
	}
		std::cout << "\n\n";
	{
		Ice B;
		std::cout << B.getType();
		std::cout << "\n\n";
		
		Ice D(B);
		std::cout << D.getType() + "\n";
	}
		std::cout << "\n\n";
		
	delete cure;
	delete ice;

	ICharacter *hisham = new Character("Hisham");
	std::cout << hisham->getName() << "\n";
	hisham->equip(new Cure());
	hisham->unequip(0);
	hisham->unequip(1);
	hisham->equip(new Ice());
	
	hisham->use(0, *hisham);
	hisham->use(1, *hisham);
	
	std::cout << "\n\n";


	Character *temp;
	Character *deia = new Character("deia");
	std::cout << deia->getName() << "\n";
	deia->equip(new Cure());
	deia->use(0, *deia);
	deia->use(1, *deia);
	std::cout << "\n\n";

	temp = static_cast<Character *>(hisham);
	*deia = *temp;

	deia->use(0, *deia);
	deia->use(1, *deia);
	delete deia;
	
	delete hisham;

    std::cout << "===== END OF randomTests TESTS =====\n" << std::endl;
}

int main() {
    basicTests();
    inventoryTests();
    deepCopyTests();
    sourceTests();
	randomTests();

    return 0;
}

