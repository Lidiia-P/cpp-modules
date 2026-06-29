#include "ScalarConverter.hpp"

static ParsedValue parse(const std::string &literal) {
	ParsedValue pv = {};
	// 1. char literal
	if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]))
	{
		pv.type = CHAR;
		pv.c = literal[0];
		return pv;
	}
	// 2. pseudo-literals
	if (literal == "nanf" || literal == "+inff" || literal == "-inff" ||
		literal == "nan" || literal == "+inf" || literal == "-inf")
	{
		pv.type = PSEUDO;
		return pv;
	}
	// 3. int
	if (isInt(literal, pv.i))
	{
		pv.type = INT;
		return pv;
	}
	// 4. float
	if (isFloat(literal, pv.f))
	{
		pv.type = FLOAT;
		return pv;
	}
	// 5. double
	if (isDouble(literal, pv.d))
	{
		pv.type = DOUBLE;
		return pv;
	}

	pv.type = INVALID;
	return pv;
}

void ScalarConverter::convert(std::string literal) {
	ParsedValue pv = parse(literal);
	switch (pv.type)
	{
		case INVALID:
			std::cout << "Invalid input!\n";
			break;
		case CHAR:
			printChar(pv.c);
			break;
		case PSEUDO:
			printPseudo(literal);
			break;
		case INT:
			printInt(pv.i);
			break;
		case FLOAT:
			printFloat(pv.f);
			break;
		case DOUBLE:
			printDouble(pv.d);
			break;
	}
}

