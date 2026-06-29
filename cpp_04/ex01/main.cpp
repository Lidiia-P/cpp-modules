#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() 
{
	const Animal* animals[6];

	std::cout << "\n--- Creating animals ---\n";
	for (int i = 0; i < 3; i++)
		animals[i] = new Dog();
	for (int i = 3; i < 6; i++)
		animals[i] = new Cat();
	std::cout << "\n--- Animals' sound ---\n";
	for (int i = 0; i < 6; i++)
		animals[i]->makeSound();

	 std::cout << "\n--- Deep copy test ---\n";
		// Cat basic;
		// {
		// 	Cat tmp = basic;   // copy constructor
		// }
		Dog basic;
		{
			Dog tmp = basic;   // copy constructor
		}
	std::cout << "\n--- Kill animals ---\n";
	for (int i = 0; i < 6; i++)
		delete animals[i];
	return 0;
}

// Why is the destructor virtual?”
// “Because deleting a derived object through a base-class pointer 
// without a virtual destructor causes undefined behavior and prevents 
// derived destructors from being called.”

// WrongAnimal::makeSound() is not virtual, so when calling it through a WrongAnimal*,
// C++ uses static binding and ignores the real object type. 
// This is why WrongCat::makeSound() is never called