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
		std::vector<int>	_sortedVector;
		std::deque<int>		_sortedDeque;

		std::vector<int>	_vector;
		std::deque<int>		_deque;

		double				_vectorTime;
		double				_dequeTime;

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
		void	parse(int argc, char **argv);
		void	sortVector();
		void	sortDeque();
		void	printResults() const;
		const std::vector<int>	&getVectorData() const { return _sortedVector; }
		const std::deque<int>	&getDequeData() const { return _sortedDeque; }

};

#endif