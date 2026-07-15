#include "PmergeMe.hpp"
#include <iostream>

// int main(int argc, char **argv)
// {
// 	(void)argv;
// 	if (argc < 2)
// 	{
// 		std::cout << "Invalid input! Usage: ./name numbers \n";
// 		return 1;
// 	}

// 	try {
	
// 	}
// 	catch(const std::exception &e) {
// 		std::cerr << e.what() << std::endl;
// 		return 1;
// 	}
// 	return 0;
// }

int main (){
	std::vector<int> arr {7, 21, 49, 63, 37, 15, 45, 75, 23, 66, 99};
	PmergeMe sort;

	sort.sortVector(arr);
	std::vector<int> sorted = sort.getData();
	std::cout << "Print out sorted" << std::endl;
	for (std::vector<int>::const_iterator it = sorted.begin(); it != sorted.end(); ++it)
		std::cout << *it << ' ';
	std::cout << std::endl;
	return 0;
}