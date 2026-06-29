#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() 
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	// const WrongAnimal* meta = new WrongAnimal();
	// const Animal* j = new Dog();
	// const WrongAnimal* i = new WrongCat();
	
	std::cout << j->getType() << " " << std::endl; 
	std::cout << i->getType() << " " << std::endl; 
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete j;
	delete i;
	delete meta;
	return 0;
}

// Why is the destructor virtual?”
// Your answer (short and perfect):
// “Because deleting a derived object through a base-class pointer 
// without a virtual destructor causes undefined behavior and prevents 
// derived destructors from being called.”

// WrongAnimal::makeSound() is not virtual, so when calling it through a WrongAnimal*,
// C++ uses static binding and ignores the real object type. 
// This is why WrongCat::makeSound() is never called