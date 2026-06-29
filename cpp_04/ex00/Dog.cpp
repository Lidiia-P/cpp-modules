#include "Dog.hpp"

// -------------------- MEMBER FUNCTIONS --------------------
void Dog::makeSound(void) const {
	std::cout << "BARK BARK!!!!" << std::endl;
}
std::string Dog::getType(void) const {
	return (type);
}

// -------------------- CONSTRUCTORS / DESTRUCTOR ------------------
Dog::Dog(void) : Animal(){
	type = "Dog";
	std::cout << "Dog was found" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other){
	std::cout << "Dog cloned itself" << std::endl;
}

Dog& Dog::operator=(const Dog& other){
	if (this != &other)
		Animal::operator=(other);
	return (*this);
}

Dog::~Dog(void){
	std::cout << "Dog ran away" << std::endl;
}