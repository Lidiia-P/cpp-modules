#include "Zombie.hpp"

int main() {
	int n = 6;
	Zombie* horde = zombieHorde(n, "FOO");

	for (int i = 0 ; i < n; i++)
		horde->announce();
	delete[] horde;
	return (0);
}