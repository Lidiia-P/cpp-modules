#ifndef CLASS_WRONGCAT_HPP
# define CLASS_WRONGCAT_HPP
# include <iostream>
# include <string>
# include <fstream>
#include "WrongAnimal.hpp"

class WrongCat : virtual public WrongAnimal {
	public:
		WrongCat(void); // Default constructor
		WrongCat(const WrongCat& other);// Copy constructor = creation
		WrongCat& operator=(const WrongCat& other);// Copy assignment = replacement
		~WrongCat(void); // 4. Destructor

		void makeSound(void) const;
		std::string getType(void) const;
};

#endif