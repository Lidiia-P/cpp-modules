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
		Span() = default;
		Span(unsigned int num) : _maxSize(num) {};
		Span(const Span& other);

		Span& operator=(const Span& other);

		~Span() = default;

		void addNumber(int n);
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;

		template <typename It>
		void	addRange(It begin, It end){
			auto diff = std::distance(begin, end);
			if (diff < 0)
				throw std::runtime_error("Invalid range");

			if (_values.size() + diff > _maxSize)
				throw std::runtime_error("Not enough space");

			_values.insert(_values.end(), begin, end);
		}

		const std::vector<int> getValues() { return _values; };
};

#endif