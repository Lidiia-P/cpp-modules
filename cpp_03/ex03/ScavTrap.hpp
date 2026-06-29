#ifndef CLASS_SCAVTRAP_HPP
# define CLASS_SCAVTRAP_HPP
# include <iostream>
# include <string>
# include <fstream>
# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap{
	public:
		ScavTrap(void); // Default constructor
		ScavTrap(const std::string& name); // Parameterized constructor
		ScavTrap(const ScavTrap& other);// Copy constructor = creation
		ScavTrap& operator=(const ScavTrap& other);// Copy assignment = replacement
		~ScavTrap(void); // 4. Destructor

		void guardGate(void);
		void attack(const std::string& target);
};

#endif