#include "ScalarConverter.hpp"

void printChar(char c) {
	if (!std::isprint(static_cast<unsigned char>(c)))
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: '" << c << "'\n";
	std::cout << "int: " << static_cast<int>(c) << "\n";
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(c) << "f\n";
	std::cout << "double: " << static_cast<double>(c) << "\n";
}

void printPseudo(const std::string& str)
{
	std::cout << "char: impossible\n";
	std::cout << "int: impossible\n";
	std::cout << std::fixed << std::setprecision(1);

	if (str == "nanf" || str == "+inff" || str == "-inff") {
		std::cout << "float: "  << str << "\n";
		std::cout << "double: " << str.substr(0, str.size() - 1) << "\n";
	} else {
		std::cout << "float: "  << str << "f\n";
		std::cout << "double: " << str << "\n";
	}
}

void printInt(long i){
	if (i < 0 || i > 127)
		std::cout << "char: impossible\n";
	else if (!std::isprint(static_cast<unsigned char>(i)))
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: '" << static_cast<char>(i) << "'\n";
	std::cout << "int: " << static_cast<int>(i) << "\n";
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(i) << "f\n";
	std::cout << "double: " << static_cast<double>(i) << "\n";
}

void printFloat(float f){
	if (f < 0 || f > 127)
		std::cout << "char: impossible\n";
	else if (!std::isprint(static_cast<unsigned char>(f)))
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: '" << static_cast<char>(f) << "'\n";

	if (f < INT_MIN || f > INT_MAX)
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << static_cast<int>(f) << "\n";

	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(f) << "f\n";
	std::cout << "double: " << static_cast<double>(f) << "\n";
}

void printDouble(double d){
	if (d < 0 || d > 127)
		std::cout << "char: impossible\n";
	else if (!std::isprint(static_cast<unsigned char>(d)))
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: '" << static_cast<char>(d) << "'\n";

	if (d < INT_MIN || d > INT_MAX)
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << static_cast<int>(d) << "\n";

	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(d) << "f\n";
	std::cout << "double: " << static_cast<double>(d) << "\n";
	
}