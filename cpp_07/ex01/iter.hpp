#ifndef CLASS_ITER_HPP
# define CLASS_ITER_HPP
# include <iostream>
# include <string>

template <typename T>
void	iter(const T *array, const int size, void (*func)(const T&)) {
	for (int i = 0; i < size; i++) {
		func(array[i]);
	}
}


template <typename T>
void	iter(T *array, const int size, void (*func)(T&)) {
	for (int i = 0; i < size; i++) {
		func(array[i]);
	}
}

#endif