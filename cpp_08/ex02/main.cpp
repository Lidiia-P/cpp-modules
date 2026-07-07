#include <iostream>
#include <list>
#include "MutantStack.hpp"

int main()
{
	std::cout << "====== Original MutantStack ======="<< std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);

	std::cout << "size: " << mstack.size() << std::endl;
	std::cout << "top: " <<mstack.top() << std::endl << std::endl;

	std::cout << "====== MutantStack popped top element ======="<< std::endl;
	mstack.pop();

	std::cout << "size: " << mstack.size() << std::endl;
	std::cout << "top: " <<mstack.top() << std::endl << std::endl;

	std::cout << "====== MutantStack added 4 more elements (5 together) ======="<< std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	std::cout << "size: " << mstack.size() << std::endl;
	std::cout << "top: " <<mstack.top() << std::endl << std::endl;

	std::cout << "====== MutantStack iterators ======="<< std::endl;

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	std::cout << "it[0]: " << *it << std::endl;
	++it;
	std::cout << "++it[1]: " << *it << std::endl;
	--it;
	std::cout << "--it[0]: " << *it << std::endl;

	while (it != ite) {
		std::cout << "MutantStack: " << *it << std::endl;
		++it;
	}
	std::cout << std::endl;

	std::cout << "====== std::stack check (prints from top to bottom) ======="<< std::endl;

	std::stack<int> s(mstack);
	while (!s.empty()) {
		std::cout << "std::stack: " << s.top() << std::endl;
		s.pop();
	}
	return 0;
}

// int main()
// {
// 	std::cout << "====== Original std::list ======="<< std::endl;
// 	std::list<int> mstack;
// 	mstack.push_back(5);
// 	mstack.push_back(17);

// 	std::cout << "size: " << mstack.size() << std::endl;
// 	std::cout << "top: " <<mstack.back() << std::endl << std::endl;

// 	std::cout << "====== std::list popped top element ======="<< std::endl;
// 	mstack.pop_back();

// 	std::cout << "size: " << mstack.size() << std::endl;
// 	std::cout << "top: " <<mstack.back() << std::endl << std::endl;

// 	std::cout << "====== std::list added 4 more elements (5 together) ======="<< std::endl;
// 	mstack.push_back(3);
// 	mstack.push_back(5);
// 	mstack.push_back(737);
//  mstack.push_back(0);

// 	std::cout << "size: " << mstack.size() << std::endl;
// 	std::cout << "top: " <<mstack.back() << std::endl << std::endl;

// 	std::cout << "====== std::list iterators ======="<< std::endl;

// 	std::list<int>::iterator it = mstack.begin();
// 	std::list<int>::iterator ite = mstack.end();

// 	std::cout << "it[0]: " << *it << std::endl;
// 	++it;
// 	std::cout << "++it[1]: " << *it << std::endl;
// 	--it;
// 	std::cout << "--it[0]: " << *it << std::endl;

// 	while (it != ite) {
// 		std::cout << "std::list: " << *it << std::endl;
// 		++it;
// 	}
// 	std::cout << std::endl;

// 	return 0;
// }