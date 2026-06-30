#ifndef CLASS_SPAN_HPP
# define CLASS_SPAN_HPP
# include <iostream>
# include <stdexcept>
# include <vector>
# include <algorithm>
# include <limits>
# include <iterator>

class Span {
	private:
		unsigned int		_maxSize;
		std::vector<int>	_values;
	public:
		Span() : _maxSize(0) {};
		Span(unsigned int num) : _maxSize(num) {};
		Span(const Span& other);

		Span& operator=(const Span& other);

		~Span() = default;

		void addNumber(int n);
};

#endif