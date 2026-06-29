#ifndef CLASS_HUMANA_HPP
# define CLASS_HUMANA_HPP
# include <iostream>
# include <string>
# include "Weapon.hpp"
# include "HumanA.hpp"
# include "HumanB.hpp"

class HumanA {
	private: 
		std::string name;
		Weapon& weapon;
	public:
		HumanA(const std::string& name, Weapon& weapon);
		~HumanA(void);
		void attack(void);
};

#endif