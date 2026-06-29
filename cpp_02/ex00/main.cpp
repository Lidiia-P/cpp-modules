#include "Fixed.hpp"

// int main( void ) {
// 	Fixed a;
// 	Fixed b( a );
// 	Fixed c;

// 	c = b;
// 	std::cout << a.getRawBits() << std::endl;
// 	std::cout << b.getRawBits() << std::endl;
// 	std::cout << c.getRawBits() << std::endl;

// 	return 0;
// 	}

int main() {
	Fixed a;
	Fixed b( a );
	Fixed c;
	
	
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	a.setRawBits(42);
	b.setRawBits(42);
	c = b;
	std::cout << "After setting raw bits:" << std::endl;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return 0;
}