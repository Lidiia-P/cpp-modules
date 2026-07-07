#ifndef CLASS_ARRAY_HPP
# define CLASS_ARRAY_HPP
# include <iostream>
# include <string>
# include <cstdlib>

template <typename T>
class Array {
	private:
		unsigned int	_size;
		T*				_data;
	public:
		Array() : _size(0), _data(nullptr) {};
		Array(unsigned int s);
		Array(const Array &other);
		~Array() { delete[] _data; };

		Array& operator=(const Array &other);
		T& operator[](unsigned int index);
		const T& operator[](unsigned int index) const;

		unsigned int size() const;
};

#include "Array.tpp"

#endif