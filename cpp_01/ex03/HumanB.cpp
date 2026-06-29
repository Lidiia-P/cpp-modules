#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

void HumanB::setWeapon(Weapon& setWeapon) {
	this->weapon = &setWeapon;
}

void HumanB:: attack(void)
{
	if (weapon == NULL)
	{
		std::cout << name << " has no weapon" << std::endl;
		return ;
	}
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

HumanB:: HumanB(const std::string& name) : name(name), weapon(NULL) {
}

HumanB:: ~HumanB(void) {
	//std::cout << name << " is destroyed\n";
}