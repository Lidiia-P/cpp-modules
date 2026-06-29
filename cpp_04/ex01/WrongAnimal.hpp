#ifndef CLASS_WRONGANIMAL_HPP
# define CLASS_WRONGANIMAL_HPP
# include <iostream>
# include <string>
# include <fstream>

class WrongAnimal {
	protected: 
		std::string	type;

	public:
		WrongAnimal(void); // Default constructor
		WrongAnimal(const WrongAnimal& other);// Copy constructor = creation
		WrongAnimal& operator=(const WrongAnimal& other);// Copy assignment = replacement
		virtual ~WrongAnimal(void); // 4. Destructor

		void makeSound(void) const;
		std::string getType(void) const;
};

#endif

