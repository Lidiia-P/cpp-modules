#ifndef CLASS_HUMANB_HPP
# define CLASS_HUMANB_HPP
# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanB {
	private: 
		std::string name;
		Weapon* weapon;
	public:
		void setWeapon(Weapon& setWeapon);
		HumanB(const std::string& name);
		~HumanB(void);
		void attack(void);
};

#endif