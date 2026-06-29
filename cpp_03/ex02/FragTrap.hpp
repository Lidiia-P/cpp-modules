#ifndef CLASS_FRAGTRAP_HPP
# define CLASS_FRAGTRAP_HPP
# include <iostream>
# include <string>
# include <fstream>
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"

class FragTrap : public ClapTrap {
	public:
		FragTrap(void); // Default constructor
		FragTrap(const std::string& name); // Parameterized constructor
		FragTrap(const FragTrap& other);// Copy constructor = creation
		FragTrap& operator=(const FragTrap& other);// Copy assignment = replacement
		~FragTrap(void); // 4. Destructor

		void highFivesGuys(void);
		void attack(const std::string& target);
};

#endif