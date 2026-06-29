#ifndef CLASS_CLAPTRAP_HPP
# define CLASS_CLAPTRAP_HPP
# include <iostream>
# include <string>
# include <fstream>

class ClapTrap {
	protected: 
		std::string	name;
		unsigned int hitPoints;
		unsigned int energyPoints;
		unsigned int damage;

	public:
		ClapTrap(void); // Default constructor
		ClapTrap(const std::string& name); // Parameterized constructor 
		ClapTrap(const ClapTrap& other);// Copy constructor = creation
		ClapTrap& operator=(const ClapTrap& other);// Copy assignment = replacement
		virtual ~ClapTrap(void); // 4. Destructor

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif