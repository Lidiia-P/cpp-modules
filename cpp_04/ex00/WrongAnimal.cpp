#include "WrongAnimal.hpp"
// -------------------- MEMBER FUNCTIONS --------------------
void WrongAnimal::makeSound(void) const{
	std::cout << "*** An unrecognized WRONG animal sound ***" << std::endl;
}

std::string WrongAnimal::getType(void) const{
	return (type);
}

// -------------------- CONSTRUCTORS / DESTRUCTOR ------------------
WrongAnimal::WrongAnimal(void) : type("Unknown"){
	std::cout << "Wrong type of animal" << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type){
	std::cout << "WrongAnimal cloned itself" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other){
	if (this != &other)
		type = other.type;
	return (*this);
}

WrongAnimal::~WrongAnimal(void){
	std::cout << "WrongAnimal disappeared" << std::endl;
}