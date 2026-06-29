#ifndef CLASS_ANIMAL_HPP
# define CLASS_ANIMAL_HPP
# include <iostream>
# include <string>
# include <fstream>

// virtual member function = "method"
// this makes the program to decide which method to use during the 
// execution (and not compilation)

class Animal {
	protected: 
		std::string	type;

	public:
		Animal(void); // Default constructor
		Animal(const Animal& other);// Copy constructor = creation
		Animal& operator=(const Animal& other);// Copy assignment = replacement
		virtual ~Animal(void); // 4. Destructor

		virtual void makeSound(void) const;
		std::string getType(void) const;
};

#endif