#ifndef CLASS_HARL_HPP
# define CLASS_HARL_HPP
# include <iostream>
# include <string>
#include <fstream>

class Harl {
	private: 
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
	public:
		void complain(std::string level);
		Harl(void);
		~Harl(void);
};

#endif