
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

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
    std::cout << "=== DiamondTrap Test ===" << std::endl;

    DiamondTrap a;
    // DiamondTrap dt("DI4M-TP");

    // dt.attack("Badass");       // inherited from ScavTrap
    // dt.takeDamage(30);         // ClapTrap function
    // dt.beRepaired(20);         // ClapTrap function
    // dt.whoAmI();               // DiamondTrap-specific

    // std::cout << "\n=== Copy / Assignment Test ===" << std::endl;
    // DiamondTrap copy(dt);      // copy constructor
    // copy.attack("Skag");
    // DiamondTrap assign;
    // assign = dt;               // assignment operator
    // assign.whoAmI();

    std::cout << "\n=== End of Test ===" << std::endl;
    return 0;
}


