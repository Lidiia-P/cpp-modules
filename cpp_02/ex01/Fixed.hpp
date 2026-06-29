#ifndef CLASS_FIXED_HPP
# define CLASS_FIXED_HPP
# include <iostream>
# include <string>
# include <fstream>
# include <cmath>

class Fixed {
	private: 
		int rawBits;
		static const int fractionalBits = 8; // search why i need it
	public:
		//constructors
		Fixed(void);
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed& other);

		// operator
		Fixed& operator=(const Fixed& other);

		// destructor
		~Fixed(void);

		float toFloat( void ) const;
		int toInt( void ) const;
};

//insertion operator
std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif