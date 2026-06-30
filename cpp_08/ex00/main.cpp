#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <iterator>

int main(void)
{
	std::cout << "==== Vector=======" << std::endl;
	std::vector<int> container = {3, 5, 8 ,0 ,5363, 15};
	try
	{
		auto result = easyfind(container, 5363);
		std::cout << "Found in vector: " << *result << std::endl;
		std::cout << "At index: " << std::distance(container.begin(), result) << std::endl << std::endl;

		easyfind(container, 99); // throws
	}
	catch(const std::exception& e)
	{
		std::cerr << "vector: " << e.what() << '\n' << std::endl;
	}

	std::cout << "==== List=======" << std::endl;
	std::list<int> lst = {5, 15, 25, 35};
	try
	{
		auto result = easyfind(lst, 15);
		std::cout << "Found in list: " << *result << std::endl;
		std::cout << "At index: " << std::distance(lst.begin(), result) << std::endl << std::endl;

		easyfind(container, 99); // throws
	}
	catch(const std::exception& e)
	{
		std::cerr << "list: " << e.what() << '\n' << std::endl;
	}

	std::cout << "==== Deque =======" << std::endl;
	std::deque<int> deq = {100, 200, 300};
	try
	{
		auto result = easyfind(deq, 300);
		std::cout << "Found in deque: " << *result << std::endl;
		std::cout << "At index: " << std::distance(deq.begin(), result) << std::endl << std::endl;

		easyfind(container, 99); // throws
	}
	catch(const std::exception& e)
	{
		std::cerr << "deque: " << e.what() << '\n' << std::endl;
	}

	return 0;
}

// vector — default choice, fast random access, only add/remove at the end

// deque — need fast insert/remove at both front and back, e.g. a queue

// list — need to insert/remove anywhere in the middle frequently, don't need index access