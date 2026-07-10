#include <fstream>
#include <sstream>
#include <cstdlib>
#include <stdexcept>
#include <cctype>
#include <iostream>
#include "RPN.hpp"

// $> ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
// 42
// $> ./RPN "7 7 * 7 -"
// 42

// -------------------- MEMBER FUNCTIONS PUBLIC --------------------

Operator RPN::stringToEnum(const std::string &input) {
	if (input == "*") return MULT;
	if (input == "/") return DIV;
	if (input == "+") return PlUS;
	if (input == "-") return MINUS;
	return UNKNOWN;
}

// Operator op = stringToEnum();

// 	switch (op)
// 	{
// 	case MULT:
		
// 		break;
// 	case DIV:
		
// 		break;
// 	case PlUS:

// 		break;
// 	case MINUS:
		
// 		break;
// 	case UNKNOWN:
// 		throw std::runtime_error("Error");
// 	}

void RPN::pushStack(char **input) {
	std::cout << "size: " << sizeof(input) << std::endl;
	
	for (int i = sizeof(input) - 1; i > 0; i-- )
	{
		_data.push(atoi(input[i]));
		std::cout << "std::stack: " << _data.top() << std::endl;
	}
}

// -------------------- MEMBER FUNCTIONS PRIVATE --------------------

