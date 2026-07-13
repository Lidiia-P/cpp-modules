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
	if (input == "+") return PLUS;
	if (input == "-") return MINUS;
	return UNKNOWN;
}

void RPN::process(const std::string &input) {

	if (_data.size() < 2)
		throw std::runtime_error("Error");
	Operator op = stringToEnum(input);

	int left = _data.top();
	_data.pop();
	int right = _data.top();
	_data.pop();

	switch (op)
	{
	case MULT:
		_data.push(right * left);
		break;
	case DIV:
		if (left == 0)
			throw std::runtime_error("Division by zero");
		_data.push(right / left);
		break;
	case PLUS:
		_data.push(right + left);
		break;
	case MINUS:
		_data.push(right - left);
		break;
	case UNKNOWN:
		throw std::runtime_error("Error");
	}
}

void RPN::calculate(const std::string &input) {
	
	std::istringstream	iss(input);
	std::string			token;

	while (iss >> token)
	{
		if ((token.size() == 1 && token[0] >= '0' && token[0] <= '9'))
			_data.push(token[0] - '0');
		else if (stringToEnum(token) != UNKNOWN)
			process(token);
		else
			throw std::runtime_error("Error");
	}

	if (_data.size() != 1)
		throw std::runtime_error("Invalid expression");

	std::cout << _data.top() << std::endl;
}
