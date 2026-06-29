#include "DiamondTrap.hpp"
// -------------------- MEMBER FUNCTIONS --------------------
 void DiamondTrap::whoAmI(void) {
	std::cout << name << " - this is my DiamondTrap name" << std::endl;
	std::cout << ClapTrap::name << " - this is my ClapTrap name" << std::endl;
 }

// -------------------- CONSTRUCTORS / DESTRUCTOR ------------------
DiamondTrap::DiamondTrap(void) 
	: ClapTrap("default_clap_name") {
		this->name = "default";
		hitPoints = 100;
		energyPoints = 50;
		damage = 30;
	std::cout << hitPoints << std::endl;
	std::cout << energyPoints << std::endl;
	std::cout << damage << std::endl;
	std::cout << "DiamondTrap default constructor called for " << name << std::endl;
}

DiamondTrap:: DiamondTrap(const std::string& name)
		: ClapTrap(name + "_clap_name") {
		this->name = name;
		hitPoints = FragTrap::hitPoints;
		energyPoints = ScavTrap::energyPoints;
		damage = FragTrap::damage;
	std::cout << "DiamondTrap constructor called for " << name << std::endl;
}

DiamondTrap:: DiamondTrap(const DiamondTrap& other) : ClapTrap(other){
	this->name = other.name;
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &other) {
	if (this != &other)
		ClapTrap::operator=(other);
	this->name = other.name;
	std::cout << "DiamondTrap copy assignment operator called." << std::endl;
	return (*this);
}

DiamondTrap:: ~DiamondTrap(void) {
	std::cout << "DiamondTrap destructor called for " << this->name << std::endl;
}