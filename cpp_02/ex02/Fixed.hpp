#ifndef CLASS_FIXED_HPP
# define CLASS_FIXED_HPP
# include <iostream>
# include <string>
# include <fstream>
# include <cmath>

class Fixed {
	private: 
		int rawBits;
		static const int fractionalBits = 8;

	public:
		//Constructors
		Fixed(void);
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed& other);

		// Assigment operator
		Fixed& operator=(const Fixed& other);

		// Destructor
		~Fixed(void);

		// Conversion
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;

		// Arithmetic
		Fixed operator+(const Fixed& other) const;
		Fixed operator-(const Fixed& other) const;
		Fixed operator*(const Fixed& other) const;
		Fixed operator/(const Fixed& other) const;

		// Comparison
		bool operator==(const Fixed& other) const;
		bool operator!=(const Fixed& other) const;
		bool operator>(const Fixed& other) const;
		bool operator<(const Fixed& other) const;
		bool operator>=(const Fixed& other) const;
		bool operator<=(const Fixed& other) const;

		// Increment / Decrement
		Fixed &operator++(void); // pre-increment
		Fixed operator++(int); // post-increment
		Fixed &operator--(void); // pre-decrement
		Fixed operator--(int); // post-decrement

		// Static min/max
		static Fixed &min(Fixed &a, Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		const static Fixed &min(const Fixed &a, const Fixed &b);
		const static Fixed &max(const Fixed &a, const Fixed &b);
};

//Insertion operator
std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif