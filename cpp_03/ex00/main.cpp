#include "ClapTrap.hpp"

// int main()
// {
// 	// ClapTrap a("WILD");

// 	// a.attack("Bandit");
// 	// a.takeDamage(3);
// 	// a.beRepaired(5);
// 	// a.takeDamage(20);
// 	// a.attack("Another Bandit");
// 	// a.beRepaired(10);

// 	ClapTrap a("STRANGE");
// 	a.attack("Bandit");  // HP = 10
// 	ClapTrap b(a);       // HP = 10, can attack
// 	b.attack("Psycho");  // works
// 	a.takeDamage(20);    // kills original
// 	b.takeDamage(2);
// 	return 0;
// }

int main()
{
	// Create a ClapTrap
	ClapTrap a("CLAP");

	// Basic attacks
	a.attack("Bandit");
	a.attack("Skag");

	// Copy constructor
	ClapTrap b(a);

	// Take damage
	a.takeDamage(3);
	a.takeDamage(20);

	// Repair
	a.beRepaired(5);
	a.beRepaired(10);

	// B attacks
	b.attack("Psycho");

	// Assignment operator
	ClapTrap c;
	c = a;
	c.beRepaired(2);

	return 0;
}
