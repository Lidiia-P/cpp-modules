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
	std::deque<int> deq(arr.begin(), arr.end());
	PmergeMe sort;

	sort.sortVector(arr);
	sort.sortDeque(deq);
	const std::vector<int>& sortedVec = sort.getVectorData();
	const std::deque<int>&  sortedDeq = sort.getDequeData();


	std::cout << "Print out sorted (vector)" << std::endl;
	for (std::vector<int>::const_iterator it = sortedVec.begin();
		it != sortedVec.end(); ++it)
		std::cout << *it << ' ';
	std::cout << std::endl;

	std::cout << "Print out sorted (deque)" << std::endl;
	for (std::deque<int>::const_iterator it = sortedDeq.begin();
		it != sortedDeq.end(); ++it)
		std::cout << *it << ' ';
	std::cout << std::endl;
	
	return 0;
}