#include "FragTrap.hpp"

// -------------------- MEMBER FUNCTIONS --------------------

void FragTrap:: highFivesGuys(void) {
	std::cout << "FragTrap " << name 
			<< " is requesting a high five!" 
			<< std::endl;
}

void FragTrap::attack(const std::string& target){
	if (hitPoints == 0 || energyPoints == 0)
	{
		std::cout << "FragTrap "<< name 
				<< " can't attack (no hit points or energy left)" 
				<< std::endl;
		return ;
	}
	energyPoints--;
	std::cout << "FragTrap " << name << " attacks " << target << ", causing " 
			<< damage << " points of damage!" << std::endl;
}

// -------------------- CONSTRUCTORS / DESTRUCTOR ------------------
FragTrap::FragTrap(void) 
	: ClapTrap()
{
	hitPoints = 100;
	energyPoints = 100;
	damage = 30;
	std::cout << "FragTrap default constructor called for " << name << std::endl;
}

FragTrap:: FragTrap(const std::string& name)
		: ClapTrap(name) {
		hitPoints = 100;
		energyPoints = 100;
		damage = 30;
	std::cout << "FragTrap constructor called for " << name << std::endl;
}

FragTrap:: FragTrap(const FragTrap& other) : ClapTrap(other){
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &other) {
	if (this != &other)
		ClapTrap::operator=(other);
	std::cout << "FragTrap copy assignment operator called." << std::endl;
	return (*this);
}

FragTrap:: ~FragTrap(void) {
	std::cout << "FragTrap destructor called for " << this->name << std::endl;
}