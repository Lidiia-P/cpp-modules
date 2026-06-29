#include "ScavTrap.hpp"

// int main()
// {
// 	//ClapTrap a("WILD");
// 	ScavTrap a("WILDER");
// 	ScavTrap b(a);
// 	ScavTrap c;

// 	c = b;
// 	a.attack("Bandit"); // HP = 100
// 	b.attack("Psycho");  // HP = 100
// 	a.takeDamage(100);    // kills original
// 	b.takeDamage(10); 
// 	b.guardGate();

// 	return 0;
// }

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	std::cout << "=== ClapTrap Test ===" << std::endl;
	ClapTrap a("CLAP");
	a.attack("Bandit");
	a.takeDamage(3);
	a.beRepaired(5);

	std::cout << "\n=== ScavTrap Test ===" << std::endl;
	ScavTrap s("SCAV");
	s.attack("Psycho");        // inherited attack
	s.takeDamage(4);            // inherited
	s.beRepaired(2);            // inherited
	s.guardGate();              // ScavTrap-specific

	std::cout << "\n=== Copy / Assignment Test ===" << std::endl;
	ScavTrap copy(s);           // copy constructor
	copy.attack("Skag");        // ensure copy works
	ScavTrap assign;
	assign = s;                 // assignment operator
	assign.guardGate();         // check assigned object works

	std::cout << "\n=== End of Test ===" << std::endl;

	// ClapTrap* ptr = new ScavTrap("Scav");
	// delete ptr;
	return 0;
}


