#include "Fixed.hpp"

//  const outside - Calling this function will not change any member variables.
int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (rawBits);
	// return (this->rawBits);
}

void Fixed::setRawBits( int const raw ) {
	rawBits = raw;
	std::cout << "setRawBits member function called" << std::endl;
}

Fixed:: Fixed(void) : rawBits(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed:: Fixed(const Fixed& other) {
	this->rawBits = other.rawBits;
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &other) {
	if (this != &other)
	{
		this->rawBits = other.rawBits;
	}
	std::cout << "Copy assignment called" << std::endl;
	return (*this);
}

Fixed:: ~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}
