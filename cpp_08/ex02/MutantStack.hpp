#ifndef CLASS_MUTANTSTACK_HPP
# define CLASS_MUTANTSTACK_HPP
# include <iostream>
# include <string>
# include <stack>

template <typename T>
class MutantStack : public std::stack<T>{
	public:
		using iterator = typename std::stack<T>::container_type::iterator;

		MutantStack() = default;
		MutantStack(const MutantStack &other)  = default;
		~MutantStack()  = default;

		MutantStack& operator=(const MutantStack &other) = default;

		iterator begin() { return this->c.begin(); }
		iterator end() { return this->c.end(); }

};

#endif