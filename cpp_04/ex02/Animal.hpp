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
		Animal(void);
		Animal(const Animal& other);
		Animal& operator=(const Animal& other);
		virtual ~Animal(void);

		virtual void makeSound(void) const = 0; // PURE VIRTUAL
		std::string getType(void) const;
};

#endif

// A virtual function may have a default implementation,
// while a pure virtual function has no implementation in the base class
// and must be overridden to create a concrete class.