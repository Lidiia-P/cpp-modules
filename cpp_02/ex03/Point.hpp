#ifndef CLASS_POINT_HPP
# define CLASS_POINT_HPP
# include <iostream>
# include <string>
# include <fstream>
# include <cmath>
# include "Fixed.hpp"

class Point {
	private:
		Fixed const x;
		Fixed const y;
	public:
		//Constructors
		Point(void);
		Point(const float xValue, const float yValue);
		Point(const Point& other);
		
		// Assigment operator
		Point& operator=(const Point& other);

		// Destructor
		~Point(void);

		Fixed getX(void) const;
		Fixed getY(void) const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point); // or maybe move it somewhere


#endif