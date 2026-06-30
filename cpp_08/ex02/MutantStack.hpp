#ifndef CLASS_MUTANTSTACK_HPP
# define CLASS_MUTANTSTACK_HPP
# include <iostream>
# include <string>
# include <cstdlib>

template <typename T>
class MutantStack {
	public:
		MutantStack() = default;
		MutantStack(const MutantStack &other)  = default;
		~MutantStack()  = default;

		MutantStack& operator=(const MutantStack &other) = default;

};

#include "MutantStack.tpp"

#endif