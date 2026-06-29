#ifndef CLASS_FIXED_HPP
# define CLASS_FIXED_HPP
# include <iostream>
# include <string>
# include <fstream>

class Fixed {
	private: 
		int rawBits;
		static const int fractionalBits = 8;
	public:
		Fixed(void); // 1. Default constructor
		Fixed(const Fixed& other);// 2. Copy constructor = creation
		Fixed& operator=(const Fixed& other);// 3. Copy assignment = replacement
		~Fixed(void); // 4. Destructor
		int getRawBits( void ) const;
		void setRawBits( int const raw );

};

#endif