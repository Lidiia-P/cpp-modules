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
	brain = new Brain();
	std::cout << "Dog was found" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other){
	std::cout << "Dog cloned itself" << std::endl;
	brain = new Brain(*other.brain);
}

Dog& Dog::operator=(const Dog& other){
	if (this != &other)
	{
		Animal::operator=(other);
		delete brain;
		brain = new Brain(*other.brain);
	}
	return (*this);
}

Dog::~Dog(void){
	std::cout << "Dog ran away" << std::endl;
	delete brain;
}