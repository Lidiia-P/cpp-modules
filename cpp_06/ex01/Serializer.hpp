#ifndef CLASS_SERIALIZER_HPP
# define CLASS_SERIALIZER_HPP
# include <iostream>
# include <string>
# include <cstdlib>

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define BLUE_B "\033[1;34m"
# define MAGENTA "\033[0;35m"
# define RESET "\033[0m"

struct Data {
	std::string	str;
	long	i;
	double	d;
};

class Serializer {
	public:
		// Constractors
		Serializer() = delete;
		Serializer(const Serializer &other) = delete;

		// Overloaded Operators
		Serializer& operator=(const Serializer&) = delete;

		// Deconstructor
		~Serializer() =  delete;

		// Member functions
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);

};

#endif