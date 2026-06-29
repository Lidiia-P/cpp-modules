#include "Point.hpp"

Fixed Point::getX(void) const{
	return x;
}

Fixed Point::getY(void) const{
	return y;
}

//Constructors
Point::Point(void) : x(0), y(0) {
}

Point::Point(const float xValue, const float yValue) : x(Fixed(xValue)), y(Fixed(yValue)) {
}

Point::Point(const Point& other) : x(other.x), y(other.y){
}

// Assigment operator -> x, y cannot be reassigned
Point& Point::operator=(const Point& other){
	(void)other;
	return(*this);
}

// Destructor
Point::~Point(void){
}