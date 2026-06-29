#include "Fixed.hpp"

// Static min/max
Fixed &Fixed::min(Fixed &a, Fixed &b){
	if (a < b)
		return (a);
	else
		return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b){
	if (a > b)
		return (a);
	else
		return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b){
	if (a > b)
		return (a);
	else
		return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b){
	if (a > b)
		return (a);
	else
		return (b);
}

// Increment / Decrement
Fixed &Fixed::operator++(void){
	++this->rawBits;
	return (*this);
}

Fixed Fixed::operator++(int){
	Fixed temp = *this;
	--(*this);
	return temp;
}

Fixed &Fixed::operator--(void){
	++this->rawBits;
	return (*this);
}

Fixed Fixed::operator--(int){
	Fixed temp = *this;
	--(*this);
	return temp;
}

// Comparison
bool Fixed::operator==(const Fixed& other) const{
	return (this->rawBits == other.rawBits);
}

bool Fixed::operator!=(const Fixed& other) const{
	return (this->rawBits != other.rawBits);
}

bool Fixed::operator>(const Fixed& other) const{
	return (this->rawBits > other.rawBits);
}

bool Fixed::operator<(const Fixed& other) const{
	return (this->rawBits < other.rawBits);
}

bool Fixed::operator>=(const Fixed& other) const{
	return (this->rawBits >= other.rawBits);
}

bool Fixed::operator<=(const Fixed& other) const{
	return (this->rawBits <= other.rawBits);
}



// Arithmetic
Fixed Fixed::operator+(const Fixed& other) const{
	return(Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed& other) const{
	return(Fixed(this->toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(const Fixed& other) const{
	return(Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed& other) const{
	return(Fixed(this->toFloat() / other.toFloat()));
}

// Conversion
int Fixed:: toInt(void) const {
	return (rawBits >> fractionalBits);
}

float Fixed:: toFloat(void) const {
	return (rawBits / (float)(1 << fractionalBits));
}

int Fixed::getRawBits( void ) const {
	return (rawBits);
}

void Fixed::setRawBits( int const raw ) {
	rawBits = raw;
}

//Constructors
Fixed:: Fixed(const float value) {
	rawBits = roundf(value * (1 << fractionalBits));
}

Fixed:: Fixed(const int value) {
	rawBits = value << fractionalBits;
}

Fixed:: Fixed(void) : rawBits(0) {
}

Fixed:: Fixed(const Fixed& other) {
	this->rawBits = other.rawBits;
}

// Assigment operator
Fixed& Fixed::operator=(const Fixed &other) {
	if (this != &other)
	{
		this->rawBits = other.rawBits;
	}
	return (*this);
}

// Destructor
Fixed:: ~Fixed(void) {
}

//Insertion operator
std::ostream& operator<<(std::ostream& os, const Fixed& obj) {
	os << obj.toFloat();
	return (os);
}