#ifndef CLASS_BASE_HPP
# define CLASS_BASE_HPP
# include <iostream>
# include <string>
# include <cstdlib>

# define BLUE_B "\033[1;34m"
# define MAGENTA "\033[0;35m"
# define RESET "\033[0m"

class Base {
	public:
		virtual ~Base() = default;
};
	Base * generate(void);
	void identify(Base* p);
	void identify(Base& p);

#endif