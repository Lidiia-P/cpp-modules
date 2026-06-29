#ifndef CLASS_DOG_HPP
# define CLASS_DOG_HPP
# include <iostream>
# include <string>
# include <fstream>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : virtual public Animal{
	private:
		Brain *brain;
	public:
		Dog(void); // Default constructor
		Dog(const Dog& other);// Copy constructor = creation
		Dog& operator=(const Dog& other);// Copy assignment = replacement
		~Dog(void); // 4. Destructor

		void makeSound(void) const;
		std::string getType(void) const;
};

#endif