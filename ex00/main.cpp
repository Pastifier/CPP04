#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(void) {
DEBUG_PRINT("------------------ SECTION ------------------");

	Animal someAnimal;

	DEBUG_PRINT(someAnimal.getType());
	someAnimal.setType("Cat");
	DEBUG_PRINT(someAnimal.getType());

DEBUG_PRINT("------------------ SECTION ------------------");

	Animal newAnimal(someAnimal);

	DEBUG_PRINT(newAnimal.getType());
	newAnimal.setType("Cat");
	DEBUG_PRINT(newAnimal.getType());

DEBUG_PRINT("------------------ SECTION ------------------");

	Animal newestAnimal = newAnimal;

	DEBUG_PRINT(newestAnimal.getType());
	newestAnimal.setType("Dog");
	DEBUG_PRINT(newestAnimal.getType() << "\n");

	someAnimal.setType("Dolphin");
	newestAnimal = someAnimal;
	DEBUG_PRINT(newestAnimal.getType());

DEBUG_PRINT("------------------ SECTION ------------------");

	newAnimal.makeSound();

DEBUG_PRINT("---------- SECTION : Dog <DEFAULT> ----------");

	Dog someDog;

	DEBUG_PRINT(someDog.getType());
	someDog.makeSound();

DEBUG_PRINT("---------- SECTION : Dog <CPYCNST> ----------");

	Dog newDog(someDog);

	DEBUG_PRINT(newDog.getType());
	newDog.makeSound();

DEBUG_PRINT("---------- SECTION : Cat <DEFAULT> ----------");

	Cat someCat;

	DEBUG_PRINT(someCat.getType());
	someCat.makeSound();

DEBUG_PRINT("---------- SECTION : Cat <CPYCNST> ----------");

	Cat newCat(someCat);

	DEBUG_PRINT(newCat.getType());
	newCat.makeSound();

DEBUG_PRINT("---------- SECTION W Cat <DEFAULT> ----------");

	WrongAnimal* wrongAnimal = new WrongCat();

	DEBUG_PRINT(wrongAnimal->getType());
	wrongAnimal->makeSound();
	WrongCat* wrongCat = (WrongCat*)wrongAnimal;
	wrongCat->makeSound();

DEBUG_PRINT("------------------ SUBJECT ------------------");

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	Cat* catDog = (Cat*)j; // To show that virtual was used.
	std::cout << "\t";
	catDog->makeSound();

	Dog* datCog = (Dog*)i; // To show that virtual was used.
	std::cout << "\t";
	datCog->makeSound();

DEBUG_PRINT("------------------ SECTION ------------------");

	delete wrongAnimal;
	delete meta;
	delete j;
	delete i;

	return 0;
}
