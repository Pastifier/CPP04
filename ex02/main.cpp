#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(void) {
DEBUG_PRINT("------------------ SUBJECT ------------------");

	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();
	
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	
	i->makeSound(); //will output the cat sound!
	j->makeSound();

	Cat* catDog = (Cat*)j; // To show that virtual was used.
	std::cout << "\t";
	catDog->makeSound();

	Dog* datCog = (Dog*)i; // Unneeded test, cuz virtual was used inside
	                       // the AAnimal class, but eh, I'll add it anyway.
	std::cout << "\t";
	datCog->makeSound();

DEBUG_PRINT("------------------ SECTION ------------------");

	const AAnimal* newestDog = new Dog(*(Dog*)j);
	newestDog->makeSound();
	DEBUG_PRINT("\n");

	const AAnimal* newestCat = new Cat(*(Cat*)i);
	newestCat->makeSound();
	DEBUG_PRINT("\n");

	std::ios_base::fmtflags baseFlags(std::cout.flags());

	{
		DEBUG_PRINT("Memory address held inside newestDog's `_cogito` member: "
		<<std::hex<<(unsigned long long)((Dog*)newestDog)->getCogito()
		);

		DEBUG_PRINT("Memory address held inside j's `_cogito` member: "
		<<			(unsigned long long)((Dog*)j)->getCogito()
		);
	}
	DEBUG_PRINT("\n");
	{
		DEBUG_PRINT("Memory address held inside newestCat's `_cogito` member: "
		<<std::hex<<(unsigned long long)((Cat*)newestCat)->getCogito()
		);

		DEBUG_PRINT("Memory address held inside i's `_cogito` member: "
		<<			(unsigned long long)((Cat*)i)->getCogito()
		);
	}

	std::cout.flags(baseFlags);

DEBUG_PRINT("------------------ SECTION ------------------");

	delete j;
	delete i;
	delete newestDog;
	delete newestCat;

	return 0;
}
