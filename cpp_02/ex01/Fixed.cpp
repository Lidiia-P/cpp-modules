#include "Fixed.hpp"

int Fixed:: toInt(void) const {
	return (rawBits >> fractionalBits);
}

float Fixed:: toFloat(void) const {
	return (rawBits / (float)(1 << fractionalBits));
}

Fixed:: Fixed(const float value) {
	rawBits = roundf(value * (1 << fractionalBits));
	std::cout << "Float constructor called" << std::endl;
}

Fixed:: Fixed(const int value) {
	rawBits = value << fractionalBits;
	std::cout << "Int constructor called" << std::endl;
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
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

Fixed:: ~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj) {
	os << obj.toFloat();
	return (os);
}