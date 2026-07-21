#include "PmergeMe.hpp"

// -------------------- MEMBER FUNCTIONS PUBLIC --------------------

void PmergeMe::sortVector(std::vector<int>& arr) {
	_sortedVector = fordJohnsonVector(arr);
}

void PmergeMe::sortDeque(std::deque<int>& deq) {
	_sortedDeque = fordJohnsonDeque(deq);
}