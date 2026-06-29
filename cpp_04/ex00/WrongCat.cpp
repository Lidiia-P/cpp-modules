#include "WrongCat.hpp"
// -------------------- MEMBER FUNCTIONS --------------------
void WrongCat::makeSound(void) const{
	std::cout << "WRONG MEOW!!!!" << std::endl;
}

std::string WrongCat::getType(void) const{
	return (type);
}

// -------------------- CONSTRUCTORS / DESTRUCTOR ------------------
WrongCat::WrongCat(void) : WrongAnimal(){
	type = "Wrong cat";
	std::cout << "Wrong cat was found" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other){
	std::cout << "Wrong cat cloned itself" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other){
	if (this != &other)
		WrongAnimal::operator=(other);
	return (*this);
}

WrongCat::~WrongCat(void) {
	std::cout << "Wrong cat ran away" << std::endl;
}