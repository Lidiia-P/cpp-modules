#include "Harl.hpp"

void Harl::debug(void) {
	std::cout << "[ DEBUG ]\n"
			<< "I love having extra bacon for my " 
			<< "7XL-double-cheese-triple-pickle-special- "
			<< "ketchup burger. I really do!\n"
			<< std::endl;
}

void Harl::info(void) {
	std::cout << "[ INFO ]\n"
			<< "I cannot believe adding extra bacon costs more "
			<< "money. You didn't put enough bacon in my burger! "
			<< "If you did, I wouldn't be asking for more!\n"
			<< std::endl;
}

void Harl::warning(void) {
	std::cout << "[ WARNING ]\n"
			<< "I think I deserve to have some extra bacon for free.\n"
			<< "I've been coming for years, whereas you started "
			<< "working here just last month.\n"
			<< std::endl;
}

void Harl::error(void) {
	std::cout << "[ ERROR ]\n"
			<< "This is unacceptable! I want to speak to the manager now."
			<< std::endl;
}

/* ask were it should or shouldnt be declared */
static Level stringToEnum(const std::string &input) {
	if (input == "DEBUG") return DEBUG;
	if (input == "INFO") return INFO;
	if (input == "WARNING") return WARNING;
	if (input == "ERROR") return ERROR;
	return UNKNOWN;
}

void Harl::complain(std::string level) {
	Level lvl = stringToEnum(level);

	switch (lvl)
	{
	case DEBUG:
		debug();
	case INFO:
		info();
	case WARNING:
		warning();
	case ERROR:
		error();
		break;
	case UNKNOWN:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		break;
	}
}

Harl::Harl(void){
}

Harl::~Harl(void){
}