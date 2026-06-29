#include "ScalarConverter.hpp"

bool	isDouble(const std::string &literal, double &doubleVal){
	if (literal.empty())
		return false;
	errno = 0;
	char *endptr;
	double value = std::strtod(literal.c_str(), &endptr); // base 10 forces decimal only

	if (*endptr != '\0')
		return false;
	if (errno == ERANGE)
		return false;

	doubleVal = value;
	return true;
}

bool	isFloat(const std::string &literal, float &floatVal){
	if (literal.empty() || literal[literal.size() - 1] != 'f')
		return false;
	std::string numberPart = literal.substr(0, literal.size() - 1);
	if (numberPart.empty())
		return false;

	errno = 0;
	char *endptr;
	float value = std::strtof(numberPart.c_str(), &endptr);

	if (*endptr != '\0')
		return false;
	if (errno == ERANGE)
		return false;

	floatVal = value;
	return true;
}

bool	isInt(const std::string &literal, long &intVal){
	if (literal.empty())
		return false;
	errno = 0;
	char *endptr;
	long value = std::strtol(literal.c_str(), &endptr, 10); // base 10 forces decimal only

	if (*endptr != '\0')
		return false;
	if (errno == ERANGE)
		return false;
	if (value < INT_MIN || value > INT_MAX)
		return false;

	intVal = value;
	return true;
}