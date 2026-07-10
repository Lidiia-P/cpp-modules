#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	(void)argv;
	if (argc < 2)
	{
		std::cout << "Invalid input!\n";
		return 1;
	}
	RPN rpn;
	try {
		rpn.pushStack(argv);
		
	}
	catch(const std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}