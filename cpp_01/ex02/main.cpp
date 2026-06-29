#include "Weapon.hpp"

int main() {
	std::string str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
	std::string& stringREF = str;

	std::cout << "Print addresses" << std::endl;
	std::cout << "The memory address of the string variable: " << &str << std::endl;
	std::cout << "The memory address held by stringPTR: " << stringPTR << std::endl;
	std::cout << "The memory address held by stringREF: " << &stringREF << std::endl;

	std::cout << "Print values" << std::endl;
	std::cout << "The value of the string variable: " << str << std::endl;
	std::cout << "The value held by stringPTR: " << *stringPTR << std::endl;
	std::cout << "The value held by stringREF: " << stringREF << std::endl;
	return (0);
}
