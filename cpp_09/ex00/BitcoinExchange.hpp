#ifndef CLASS_BITCOINEXCHANGE_HPP
# define CLASS_BITCOINEXCHANGE_HPP

# include <map>

class BitcoinExchange {
	private: 
		std::map<std::string, double>	_rates;

		// Member functions
		void	processLine(const std::string &line) const;
		bool	splitInputLine(const std::string &line, std::string &date, std::string &valueStr) const ;
		std::string	trim(const std::string &str) const;
		bool	parseValue(const std::string &valueStr, double &value) const;
		bool	isValidDate(const std::string &date) const;
		double	getRateForDate(const std::string &date) const;
		
	public:
		// Constractors
		BitcoinExchange(void) = default;
		BitcoinExchange(const BitcoinExchange& other) = default;

		// Overloaded Operators
		BitcoinExchange& operator=(const BitcoinExchange& other) = default;

		// Deconstructor
		~BitcoinExchange(void) = default;

		// Member functions
		void	loadDatabase(const std::string &databaseFile);
		void	processInputFile(const std::string &inputFile) const;


};

#endif