#ifndef CLASS_DIAMONDTRAP_HPP
# define CLASS_DIAMONDTRAP_HPP
# include <iostream>
# include <string>
# include <fstream>
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"


class DiamondTrap :public ScavTrap, public FragTrap {
	private:
		std::string	name;
	public:
		DiamondTrap(void); // Default constructor
		DiamondTrap(const std::string& name); // Parameterized constructor
		DiamondTrap(const DiamondTrap& other);// Copy constructor = creation
		DiamondTrap& operator=(const DiamondTrap& other);// Copy assignment = replacement
		~DiamondTrap(void); // 4. Destructor

		using ScavTrap::attack;
		void whoAmI(void);

};

#endif