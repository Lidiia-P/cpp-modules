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
	brain = new Brain();
	std::cout << "Cat was found" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other){
	std::cout << "Cat cloned itself" << std::endl;
	brain = new Brain(*other.brain);
}

Cat& Cat::operator=(const Cat& other){
	if (this != &other)
	{
		Animal::operator=(other);
		delete brain;
		brain = new Brain(*other.brain);
	}
	return (*this);
}

Cat::~Cat(void) {
	std::cout << "Cat ran away" << std::endl;
	delete brain;
}