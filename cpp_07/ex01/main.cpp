#include "iter.hpp"

void	printText(const std::string &text);
void	printInt(const int &num);
void	increase(int &num);
void	decrease(int &num);



int main(void)
{
	{
		std::string text[] = {"Hello darkness my old friend", "I've come to talk with you again"};
		std::cout << "String array:" << std::endl;
		::iter(text, 2, printText);
		std::cout << std::endl;	
	}

	{
		int	arr[] = {2, 4, 6, 8};
		std::cout << "Original int array: ";
		::iter(arr, 4, printInt);
		std::cout << std::endl;

		std::cout << "Increased int array: ";
		::iter(arr, 4, increase);
		::iter(arr, 4, printInt);
		std::cout << std::endl;

		std::cout << "Decreased int array: ";
		::iter(arr, 4, decrease);
		::iter(arr, 4, printInt);
		std::cout << std::endl << std::endl;
	}

	{
		const int	constArray[] = {10, 20, 30, 40};
		std::cout << "Original const int array: ";
		::iter(constArray, 4, printInt);
		std::cout << std::endl;
	}

	return 0;
}

void	printText( const std::string &str){
	std::cout << str << std::endl;
}

void	printInt(const int &num){
	std::cout << num << " ";
}

void	increase(int &num){
	num++;
}

void	decrease(int &num){
	num--;
}
