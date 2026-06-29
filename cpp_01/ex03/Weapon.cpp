#include "Weapon.hpp"

const std::string& Weapon::getType(void) {
	const std::string& getType = type;
	return (getType);
}

void Weapon::setType(const std::string& newType) {
	type = newType;
}

Weapon:: Weapon(const std::string& type) : type(type) {
}

Weapon:: ~Weapon(void){
}