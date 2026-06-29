#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::min( a, b ) << std::endl;
	return 0;
}


/* COMPARISON TEST */
// int main() {
// 	Fixed a(5.5f);
// 	Fixed b(10.25f);
// 	Fixed c(5.5f);

// 	// Test >
// 	std::cout << "a > b? " << (a > b) << std::endl; // 0 (false)
// 	std::cout << "b > a? " << (b > a) << std::endl; // 1 (true)

// 	// Test <
// 	std::cout << "a < b? " << (a < b) << std::endl; // 1 (true)
// 	std::cout << "b < a? " << (b < a) << std::endl; // 0 (false)

// 	// Test >=
// 	std::cout << "a >= c? " << (a >= c) << std::endl; // 1 (true)
// 	std::cout << "a >= b? " << (a >= b) << std::endl; // 0 (false)

// 	// Test <=
// 	std::cout << "a <= c? " << (a <= c) << std::endl; // 1 (true)
// 	std::cout << "b <= a? " << (b <= a) << std::endl; // 0 (false)

// 	// Test ==
// 	std::cout << "a == c? " << (a == c) << std::endl; // 1 (true)
// 	std::cout << "a == b? " << (a == b) << std::endl; // 0 (false)

// 	// Test !=
// 	std::cout << "a != b? " << (a != b) << std::endl; // 1 (true)
// 	std::cout << "a != c? " << (a != c) << std::endl; // 0 (false)

// 	return 0;
// }

/* EXPECTED RESULT OF COMPARISON*/
// a > b? 0
// b > a? 1
// a < b? 1
// b < a? 0
// a >= c? 1
// a >= b? 0
// a <= c? 1
// b <= a? 0
// a == c? 1
// a == b? 0
// a != b? 1
// a != c? 0