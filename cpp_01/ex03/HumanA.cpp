#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

void HumanA:: attack(void)
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
HumanA:: HumanA(const std::string& name, Weapon& weapon) : name(name), weapon(weapon) {
}

HumanA:: ~HumanA(void) {
	// std::cout << name << " is destroyed\n";
}