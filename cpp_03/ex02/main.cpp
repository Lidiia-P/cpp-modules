
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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



int main()
{
	std::cout << "=== ClapTrap Test ===" << std::endl;
	ClapTrap a("CLAP");
	a.attack("Bandit");
	a.takeDamage(3);
	a.beRepaired(5);

	std::cout << "\n=== ScavTrap Test ===" << std::endl;
	ScavTrap s("SCAV");
	s.attack("Psycho");        // attack
	s.takeDamage(4);            // inherited
	s.beRepaired(2);            // inherited
	s.guardGate();              // ScavTrap-specific

	std::cout << "\n=== FlagTrap Test ===" << std::endl;
	FragTrap f("FRAG");
	f.attack("Lame");        // inherited attack
	f.takeDamage(10);            // inherited
	f.beRepaired(20);            // inherited
	f.highFivesGuys();          // FragTrap-specific

	std::cout << "\n=== Copy / Assignment Test ===" << std::endl;
	FragTrap copy(f);           // copy constructor
	copy.attack("Skag");        // ensure copy works
	FragTrap assign;
	assign = f;                 // assignment operator
	assign.highFivesGuys();         // check assigned object works
	copy.highFivesGuys();

	std::cout << "\n=== End of Test ===" << std::endl;

	// ClapTrap* ptr = new ScavTrap("Scav");
	// delete ptr;
	return 0;
}


