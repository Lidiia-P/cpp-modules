#include "Cat.hpp"
// -------------------- MEMBER FUNCTIONS --------------------
void Cat::makeSound(void) const{
	std::cout << "MEOW!!!!" << std::endl;
}

std::string Cat::getType(void) const{
	return (type);
}

// -------------------- CONSTRUCTORS / DESTRUCTOR ------------------
Cat::Cat(void) : Animal(){
	type = "Cat";
	std::cout << "Cat was found" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other){
	std::cout << "Cat cloned itself" << std::endl;
}

Cat& Cat::operator=(const Cat& other){
	if (this != &other)
		Animal::operator=(other);
	return (*this);
}

Cat::~Cat(void) {
	std::cout << "Cat ran away" << std::endl;
}