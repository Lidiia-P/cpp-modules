#include <fstream>
#include <sstream>
#include <cstdlib>
#include <stdexcept>
#include <cctype>
#include <iostream>
#include "PmergeMe.hpp"

// 3, 5, 9, 7, 4

// -------------------- MEMBER FUNCTIONS PUBLIC --------------------

// int binarySearch(vector<int> &arr, int low, int high, int x) {
//     if (high >= low) {
//         int mid = low + (high - low) / 2;

//         // If the element is present at the middle
//         // itself
//         if (arr[mid] == x)
//             return mid;

//         // If element is smaller than mid, then
//         // it can only be present in left subarray
//         if (arr[mid] > x)
//             return binarySearch(arr, low, mid - 1, x);

//         // Else the element can only be present
//         // in right subarray
//         return binarySearch(arr, mid + 1, high, x);
//     }
//   return -1;
// }

void PmergeMe::sortVector(std::vector<int> &arr) {
	if (arr.size() <= 1) {
		_sortedVector = arr;
		return;
	}

	std::vector<Pair> pairs;
	bool hasLeftover = false;
	int leftover = 0;

	std::size_t i = 0;
	while (i + 1 < arr.size()) {
		int left = arr[i];
		int right = arr[i + 1];

		Pair p;
		if (left < right) {
			p.small = left;
			p.large = right;
		} else {
			p.small = right;
			p.large = left;
		}
		pairs.push_back(p);
		i += 2;
	}

	if (i < arr.size()) {
		hasLeftover = true;
		leftover = arr[i];
	}

	std::vector<int> winners;
	winners.reserve(pairs.size());
	for (std::size_t k = 0; k < pairs.size(); ++k)
		winners.push_back(pairs[k].large);

	sortVector(winners);

	std::vector<int> chain = _sortedVector;
	chain.reserve(arr.size());

	for (std::size_t k = 0; k < pairs.size(); ++k) {
		int value = pairs[k].small;
		int partner = pairs[k].large;

		std::vector<int>::iterator partnerIt =
			std::find(chain.begin(), chain.end(), partner);

		std::vector<int>::iterator pos =
			std::lower_bound(chain.begin(), partnerIt, value);

		chain.insert(pos, value);
	}

	if (hasLeftover) {
		std::vector<int>::iterator pos =
			std::lower_bound(chain.begin(), chain.end(), leftover);
		chain.insert(pos, leftover);
	}

	arr = chain;
	_sortedVector = chain;
}