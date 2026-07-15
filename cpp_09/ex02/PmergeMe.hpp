#ifndef CLASS_PMERGEME_HPP
# define CLASS_PMERGEME_HPP

# include <vector>

struct Pair {
	int small;
	int large;
};

struct PendNode {
	int small;
	int partnerLarge;
};

class PmergeMe {
	private:
		// std::vector<Pair>	pairs;
		std::vector<int> _sortedVector;

		std::vector<int> fordJohnsonVector(const std::vector<int>& input);
	public:
		// Constractors
		PmergeMe(void) = default;
		PmergeMe(const PmergeMe& other) = default;

		// Overloaded Operators
		PmergeMe& operator=(const PmergeMe& other) = default;

		// Deconstructor
		~PmergeMe(void) = default;

		// Member functions
		void sortVector(std::vector<int> &arr);
		const std::vector<int> &getData() const { return _sortedVector; }

};

#endif