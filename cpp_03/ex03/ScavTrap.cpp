#include "ScavTrap.hpp"

// -------------------- MEMBER FUNCTIONS --------------------

void ScavTrap:: guardGate(void) {
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string& target){
	if (hitPoints == 0 || energyPoints == 0)
	{
		std::cout << "ScavTrap "<< name 
				<< " can't attack (no hit points or energy left)" 
				<< std::endl;
		return ;
	}
	energyPoints--;
	std::cout << "ScavTrap " << name << " attacks " << target << ", causing " 
			<< damage << " points of damage!" << std::endl;
}

// -------------------- CONSTRUCTORS / DESTRUCTOR --------------------

ScavTrap::ScavTrap(void) 
	: ClapTrap()
{
	hitPoints = 100;
	energyPoints = 50;
	damage = 20;
	std::cout << "ScavTrap default constructor called for " << name << std::endl;
}

ScavTrap:: ScavTrap(const std::string& name)
		: ClapTrap(name) {
		hitPoints = 100;
		energyPoints = 50;
		damage = 20;
	std::cout << "ScavTrap constructor called for " << name << std::endl;
}

ScavTrap:: ScavTrap(const ScavTrap& other) : ClapTrap(other){
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other) {
	if (this != &other)
		ClapTrap::operator=(other);
	std::cout << "ScavTrap copy assignment operator called." << std::endl;
	return (*this);
}

ScavTrap:: ~ScavTrap(void) {
	std::cout << "ScavTrap destructor called for " << this->name << std::endl;
}
