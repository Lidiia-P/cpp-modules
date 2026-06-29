#ifndef ARRAY_TPP
# define ARRAY_TPP

# include <exception>

// ---------------- Constractors ------------------

template <typename T>
Array<T>::Array(unsigned int s) : _size(s) {
	_data = new T[s]();
}

template <typename T>
Array<T>::Array(const Array &other) : _size(other._size) {
	_data = new T[_size];
	for (unsigned int i = 0; i < _size; i++)
		_data[i] = other._data[i];
}

// ---------------- Operators ------------------

template <typename T>
Array<T>& Array<T>::operator=(const Array &other) {
	if (this != &other){
		T* tmp = new T[other._size]();
		delete [] _data;
		_size = other._size;
		_data = tmp;
		for (unsigned int i = 0; i < _size; i++)
			_data[i] = other._data[i];
	}
	return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int index){
	if (index >= _size)
		throw std::exception();
	return _data[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const {
	if (index >= _size)
		throw std::exception();
	return _data[index];
}

// ---------------- Member function ------------------

template <typename T>
unsigned int Array<T>::size(void) const {
	return _size;
}

#endif