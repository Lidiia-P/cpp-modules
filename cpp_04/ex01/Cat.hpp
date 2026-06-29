#ifndef CLASS_CAT_HPP
# define CLASS_CAT_HPP
# include <iostream>
# include <string>
# include <fstream>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : virtual public Animal {
	private:
		Brain *brain;
	public:
		Cat(void);
		Cat(const Cat& other);
		Cat& operator=(const Cat& other);
		~Cat(void);

		void makeSound(void) const;
		std::string getType(void) const;

};

#endif