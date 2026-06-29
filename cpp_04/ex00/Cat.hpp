#ifndef CLASS_CAT_HPP
# define CLASS_CAT_HPP
# include <iostream>
# include <string>
# include <fstream>
# include "Animal.hpp"

class Cat : virtual public Animal {
	public:
		Cat(void); // Default constructor
		Cat(const Cat& other);// Copy constructor = creation
		Cat& operator=(const Cat& other);// Copy assignment = replacement
		~Cat(void); // 4. Destructor

		void makeSound(void) const;
		std::string getType(void) const;

};

#endif