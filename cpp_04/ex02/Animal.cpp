#include "Animal.hpp"
// -------------------- MEMBER FUNCTIONS --------------------
std::string Animal::getType(void) const{
	return (type);
}

// -------------------- CONSTRUCTORS / DESTRUCTOR ------------------
Animal::Animal(void) : type("Unknown"){
	std::cout << "Unknown type of animal" << std::endl;
}
Animal::Animal(const Animal& other) : type(other.type){
	std::cout << "Animal cloned itself" << std::endl;
}

Animal& Animal::operator=(const Animal& other){
	if (this != &other)
		type = other.type;
	return (*this);
}

Animal::~Animal(void){
	std::cout << "Animal disappeared" << std::endl;
}