#ifndef CLASS_EASYFIND_HPP
# define CLASS_EASYFIND_HPP
# include <iostream>
# include <string>
# include <exception>

template <typename T>
auto	easyfind(T &container, int value) {
	auto tmp = std::find(container.begin(), container.end(), value);
	if (tmp == container.end())
		throw std::runtime_error("Value not found");
	return tmp;
}

#endif