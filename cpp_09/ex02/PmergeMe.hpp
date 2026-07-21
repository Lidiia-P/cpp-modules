#ifndef CLASS_PMERGEME_HPP
# define CLASS_PMERGEME_HPP

# include <vector>
# include <deque>

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
		std::vector<int>	_sortedVector;
		std::deque<int>		_sortedDeque;

		std::vector<int>	fordJohnsonVector(const std::vector<int>& input);
		std::deque<int>		fordJohnsonDeque(const std::deque<int>& input);
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
		void sortDeque(std::deque<int> &deq);
		const std::vector<int> &getVectorData() const { return _sortedVector; }
		const std::deque<int> &getDequeData() const { return _sortedDeque; }

};

#endif