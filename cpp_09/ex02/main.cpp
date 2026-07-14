#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	(void)argv;
	if (argc < 2)
	{
		std::cout << "Invalid input! Usage: ./name numbers \n";
		return 1;
	}

	try {
	
	}
	catch(const std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}