#ifndef CLASS_BRAIN_HPP
# define CLASS_BRAIN_HPP
# include <iostream>
# include <string>
# include <fstream>


class Brain {
	private:
		std::string ideas[100];
	public:
		//constructors
		Brain(void);
		Brain(const Brain& other);

		// operator
		Brain& operator=(const Brain& other);
		// destructor
		~Brain(void);
};

#endif