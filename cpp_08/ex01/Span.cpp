#include "Span.hpp"

// ---------------- Constractors ------------------

Span::Span(const Span& other) : _maxSize(other._maxSize) {
	for (unsigned int i = 0; i < _maxSize; i++)
		_values[i] = other._values[i];
};


// ---------------- Operators ------------------

Span& Span::operator=(const Span& other) {
	if (this != &other)
	{
		_maxSize = other._maxSize;
		for (unsigned int i = 0; i < _maxSize; i++)
			_values[i] = other._values[i];
	}
	return *this;
}

// ---------------- Member function ------------------

void Span::addNumber(int n) {
	if (_values.size() >= _maxSize)
		throw std::runtime_error("Span is full!");
	 _values.push_back(n);
}

unsigned int Span::shortestSpan() const {
	if (_values.size() < 2)
		throw std::runtime_error("Not enough elements to find a span");
	std::vector<int> tmp = _values;
	std::sort(tmp.begin(), tmp.end());

	int shortest = tmp[1] - tmp[0];
	for (int i = 0; i + 1< static_cast<int>(_maxSize); i++) {
		int diff = tmp[1 + i] - tmp[0 + i];
		if (diff < shortest)
			shortest = diff;
	}
	return (shortest);
}

unsigned int Span::longestSpan() const {
	if (_values.size() < 2)
		throw std::runtime_error("Not enough elements to find a span");
	return static_cast<unsigned int>(*std::max_element(_values.begin(), _values.end()) - *std::min_element(_values.begin(), _values.end()));
}