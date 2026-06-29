#include "ClapTrap.hpp"

// -------------------- MEMBER FUNCTIONS --------------------

void ClapTrap::attack(const std::string& target){
	if (hitPoints == 0 || energyPoints == 0)
	{
		std::cout << "ClapTrap "<< name 
				<< " can't attack (no hit points or energy left)" 
				<< std::endl;
		return ;
	}
	energyPoints--;
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing " 
			<< damage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){
	if (amount >= hitPoints)
		hitPoints = 0;
	else
		hitPoints -= amount;
	std::cout << "ClapTrap " << name << " takes "
			<< amount << " points of damage!" 
			<< " (HP: " << hitPoints << ")"
			<< std::endl;
}

void ClapTrap::beRepaired(unsigned int amount){
	if (hitPoints == 0 || energyPoints == 0)
	{
		std::cout << "ClapTrap "<< name 
				<< " can't repair (no hit points or energy left)" 
				<< std::endl;
		return ;
	}
	energyPoints--;
	hitPoints += amount;
	std::cout << "ClapTrap " << name
			<< " repairs itself for "
			<< amount << " hit points!" 
			<< " (HP: " << hitPoints << ")"
			<< std::endl;
}


// -------------------- CONSTRUCTORS / DESTRUCTOR --------------------

ClapTrap::ClapTrap(void)
	: name("Default"), hitPoints(10), energyPoints(10), damage(0)
{
	std::cout << "Default constructor called for " << name << std::endl;
}

ClapTrap:: ClapTrap(const std::string& name)
		: name(name), hitPoints(10), energyPoints(10), damage(0) {
	std::cout << "Constructor called for " << this->name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
	: name(other.name),
	hitPoints(other.hitPoints),
	energyPoints(other.energyPoints),
	damage(other.damage)
{
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other) {
	if (this != &other)
	{
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		damage = other.damage;
	}
	std::cout << "Copy assignment called" << std::endl;
	return (*this);
}

ClapTrap:: ~ClapTrap(void) {
	std::cout << "Destructor called for " << name << std::endl;
}


// Rules:
//
// attack:
// - Costs 1 energy point
// - Does nothing if hit points ≤ 0 OR energy points ≤ 0
// - Prints a message
// 
// beRepaired:
// - Costs 1 energy point
// - Does nothing if hit points ≤ 0 OR energy points ≤ 0
// - Increases hit points
// - Prints a message
// 
// takeDamage:
//  - Reduces hit points (no energy cost)
//  - Hit points should not go negative (good practice)