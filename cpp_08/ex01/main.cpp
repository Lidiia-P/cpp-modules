#include "Span.hpp"

int main(void)
{	
	{
		std::cout << "===== ORIGINAL TEST =====" << std::endl;

		Span	sp(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		// std::cout << "Print out stack" << std::endl;
		// for (auto data : sp.getValues())
		// 	std::cout << data << "\n";

		try
		{
			std::cout << "Longest: " << sp.longestSpan() << std::endl;
			std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}

	{
		std::cout << "===== DUBLICATE =====" << std::endl;

		Span	sp(4);

		sp.addNumber(20);
		sp.addNumber(30);
		sp.addNumber(30);
		sp.addNumber(10);

		try
		{
			std::cout << "Longest: " << sp.longestSpan() << std::endl;
			std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}

	{
		std::cout << "===== WITH NEGATIVE NUMBERS =====" << std::endl;

		Span	sp(4);

		sp.addNumber(2);
		sp.addNumber(-30);
		sp.addNumber(7);
		sp.addNumber(10000);

		try
		{
			std::cout << "Longest: " << sp.longestSpan() << std::endl;
			std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}

		{
		std::cout << "===== NOT ENOUGH ELEMENTS =====" << std::endl;

		Span	sp(4);

		sp.addNumber(2);

		try
		{
			std::cout << "Longest: " << sp.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}

	{
		std::cout << "===== NOT ENOUGH SPACE =====" << std::endl;

		Span	sp(2);

		sp.addNumber(2);
		sp.addNumber(3);

		try
		{
			sp.addNumber(2);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}

	{
		std::cout << "===== 10 000 RANGE =====" << std::endl;
		Span				huge(10000);
		std::vector<int>	vec(10000);

		for (int i = 0; i < 10000; i++)
			vec[i] = i;

		try
		{
			huge.addRange(vec.begin(), vec.end());
			
			// std::cout << "Print out HUGE" << std::endl;
			// for (auto data : huge.getValues())
			// 	std::cout << data << " ";
			// std::cout << std::endl;

			std::cout << "Longest: " << huge.longestSpan() << std::endl;
			std::cout << "Shortest: " << huge.shortestSpan() << std::endl << std::endl; 

			std::cout << "===== OVERFLOW via addRange =====" << std::endl;
			huge.addRange(vec.begin(), vec.end()); // throw 
		}
		catch(const std::exception& e)
		{
			std::cerr << "huge: " << e.what() << '\n' << std::endl;
		}

		std::cout << "===== NEGATIVE RANGE =====" << std::endl;
		try
		{
			huge.addRange(vec.end(), vec.begin()); // throw 
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	return 0;
}