#include <fstream>
#include <sstream>
#include <cstdlib>
#include <stdexcept>
#include <cctype>
#include <iostream>
#include "BitcoinExchange.hpp"

// -------------------- MEMBER FUNCTIONS PUBLIC --------------------

void	BitcoinExchange::loadDatabase(const std::string &databaseFile) {
	std::ifstream file(databaseFile.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: could not open database file.");

	std::string line;
	if (!std::getline(file, line))
		throw std::runtime_error("Error: database file is empty.");
	
	while (std::getline(file, line))
	{
		if (line.empty())
			continue;

		std::stringstream ss(line);
		std::string date;
		std::string strRate;

		if (!std::getline(ss, date, ',') || !std::getline(ss, strRate))
			throw std::runtime_error("Error: bad database line => " + line);
		
		double rate = std::strtod(strRate.c_str(), NULL);
		_rates[date] = rate;
	}
	if (_rates.empty())
		throw std::runtime_error("Error: database not loaded.");
}

void	BitcoinExchange::processInputFile(const std::string &inputFile) const {
	if (_rates.empty())
		throw std::runtime_error("Error: database not loaded.");
	
	std::ifstream file(inputFile.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: could not open file.");
	
	std::string line;
	if (!std::getline(file, line))
		throw std::runtime_error("Error: file is empty.");

	while (std::getline(file, line)) {
		if (line.empty())
			continue;
		processLine(line);
	}
}

// -------------------- MEMBER FUNCTIONS PRIVATE --------------------

void	BitcoinExchange::processLine(const std::string &line) const {
	std::string date;
	std::string valueStr;
	double value;

	if (!splitInputLine(line, date, valueStr))
		return ;

	date = trim(date);
	valueStr = trim(valueStr);

	if (!isValidDate(date))
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return;
	}
	if (!parseValue(valueStr, value))
		return;

	try
	{
		double rate = getRateForDate(date);
		std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

bool	BitcoinExchange::splitInputLine(const std::string &line, std::string &date, std::string &valueStr) const
{
	std::stringstream ss(line);

	if (!std::getline(ss, date, '|') || !std::getline(ss, valueStr))
	{
		std::cerr << "Error: bad input line => " << line << std::endl;
		return false;
	}
	return true;
}

std::string	BitcoinExchange::trim(const std::string &str) const {
	size_t start = 0;
	while (start < str.size() && std::isspace(static_cast<unsigned char>(str[start])))
		++start;

	size_t end = str.size();
	while (end > start && std::isspace(static_cast<unsigned char>(str[end - 1])))
		--end;
	return str.substr(start, end - start);
}

bool BitcoinExchange::parseValue(const std::string &valueStr, double &value) const {
	char *endPtr;
	value = std::strtod(valueStr.c_str(), &endPtr);

	if (endPtr == valueStr.c_str() || *endPtr != '\0')
	{
		std::cerr << "Error: bad input => " << valueStr << std::endl;
		return false;
	}
	if (value < 0)
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return false;
	}
	if (value > 1000)
	{
		std::cerr << "Error: too large a number." << std::endl;
		return false;
	}
	return true;
}

bool	BitcoinExchange::isValidDate(const std::string &date) const {
	if (date.length() != 10)
		return false;

	if (date[4] != '-' || date[7] != '-')
		return false;

	for (size_t i = 0; i < date.length(); ++i)
	{
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(static_cast<unsigned char>(date[i])))
			return false;
	}

	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if (month < 1 || month > 12)
		return false;
	if (day < 1)
		return false;

	int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	bool leapYear = ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
	if (leapYear)
		daysInMonth[1] = 29;

	if (day > daysInMonth[month - 1])
		return false;

	return true;
}

double	BitcoinExchange::getRateForDate(const std::string &date) const {
	std::map<std::string, double>::const_iterator it = _rates.lower_bound(date);

	if (it != _rates.end() && it->first == date)
		return it->second;

	if (it == _rates.begin())
		throw std::runtime_error("Error: no earlier date found.");

	--it;
	return it->second;
}