#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750

int main(void)
{
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;//

	// Test size()
	std::cout << "===== size() TEST ========"<< std::endl;
	Array<int> empty;
	std::cout << "Empty array size: " << empty.size() << std::endl;        // 0
	std::cout << "Numbers array size: " << numbers.size() << std::endl;    // 750

	Array<int> small(5);
	std::cout << "Small array size: " << small.size() << std::endl;        // 5

	Array<int> copy = small;
	std::cout << "Copy size matches: " << (copy.size() == small.size() ? "yes" : "no") << std::endl;  // yes
	return 0;
}