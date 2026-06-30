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