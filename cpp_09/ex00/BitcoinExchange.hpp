#ifndef CLASS_BITCOINEXCHANGE_HPP
# define CLASS_BITCOINEXCHANGE_HPP
# include <iostream>
# include <string>
# include <exception>

class BitcoinExchange {
	private: 

	public:
		// Constractors
		BitcoinExchange(void) = default;
		BitcoinExchange(const BitcoinExchange& other) = default;

		// Overloaded Operators
		BitcoinExchange& operator=(const BitcoinExchange& other) = default;

		// Deconstructor
		~BitcoinExchange(void) = default;

		// Member functions


		// Exceptions

};

#endif