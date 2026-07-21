#include <string>
#include <iostream>
#include "PmergeMe.hpp"

// -------------------- MEMBER FUNCTIONS PUBLIC --------------------

void	PmergeMe::parse(int argc, char **argv) {
	if (argc < 2)
		throw std::runtime_error("Error");
	
	_vector.reserve(argc - 1);
	_sortedVector.reserve(argc - 1);

	for (int i = 1; i < argc; ++i) {
		std::string s(argv[i]);

		for (unsigned char c : s)
		{
			if (!std::isdigit(c))
				throw std::runtime_error("Error");
		}

		int val;
		try
		{
			val = std::stoi(s);
		}
		catch(const std::exception& e)
		{
			throw std::runtime_error("Error");
		}

		if (val < 0)
				throw std::runtime_error("Error");

			_vector.push_back(static_cast<int>(val));
			_deque.push_back(static_cast<int>(val));
	}
}

void	PmergeMe::sortVector(void) {
	auto	start = std::chrono::high_resolution_clock::now();

	_sortedVector = fordJohnsonVector(_vector);

	auto	end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double, std::micro>	duration = end - start;
	_vectorTime = duration.count();
}

void	PmergeMe::sortDeque(void) {
	auto	start = std::chrono::high_resolution_clock::now();

	_sortedDeque = fordJohnsonDeque(_deque);

	auto	end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::micro>	duration = end - start;
	_dequeTime = duration.count();

}

void	PmergeMe::printResults(void) const {
	// Before: print original vector (_vector before sorting, or store a copy)
	std::cout << "Before: ";
	for (std::vector<int>::const_iterator it = _vector.begin();
		it != _vector.end(); ++it)
		std::cout << *it << ' ';
	std::cout << std::endl;

	// After: print sorted vector (_sortedVector)
	std::cout << "After:  ";
	for (std::vector<int>::const_iterator it = _sortedVector.begin();
		it != _sortedVector.end(); ++it)
		std::cout << *it << ' ';
	std::cout << std::endl;

	// Then print timing lines measured in sortVector / sortDeque
	std::cout	<< "Time to process a range of "
					<< _vector.size()
					<< " elements with std::vector : "
					<< _vectorTime
					<< " us"
					<< std::endl;
	
	std::cout	<< "Time to process a range of "
					<< _deque.size()
					<< " elements with std::deque : "
					<< _dequeTime
					<< " us"
					<< std::endl;
}