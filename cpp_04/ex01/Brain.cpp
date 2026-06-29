#include "Brain.hpp"
// -------------------- MEMBER FUNCTIONS --------------------


// -------------------- CONSTRUCTORS / DESTRUCTOR ------------------
Brain::Brain(void){
	std::cout << "Brain was constructed" << std::endl;
}

Brain::Brain(const Brain& other) {
	std::cout << "Brain cloned itself" << std::endl;
	*this = other;
}

Brain& Brain::operator=(const Brain& other){
	if (this != &other)
		for (int i = 0; i < 100; i++)
			ideas[i] = other.ideas[i];
	return (*this);
}

Brain::~Brain(void) {
	std::cout << "Brain was destroyed" << std::endl;
}