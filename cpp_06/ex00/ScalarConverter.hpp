#ifndef CLASS_SCALARCONVERTER_HPP
# define CLASS_SCALARCONVERTER_HPP
# include <iostream>
# include <string>
# include <cstdlib>
# include <cerrno>
# include <climits>
# include <iomanip> 

enum Type {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDO,
	INVALID
};

struct ParsedValue {
	Type	type;
	char	c;
	long	i;
	float	f;
	double	d;
};

class ScalarConverter {
	public:
		// Constractors
		ScalarConverter() = delete;
		ScalarConverter(const ScalarConverter &other) = delete;

		// Overloaded Operators
		ScalarConverter& operator=(const ScalarConverter&) = delete;

		// Deconstructor
		~ScalarConverter() =  delete;

		// Member functions
		static void convert(std::string literal);

};

bool	isInt(const std::string &literal, long &intVal);
bool	isFloat(const std::string &literal, float &floatVal);
bool	isDouble(const std::string &literal, double &doubleVal);

void printChar(char c);
void printPseudo(const std::string& str);
void printInt(long i);
void printFloat(float f);
void printDouble(double d);

#endif