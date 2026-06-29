#include "Bureaucrat.hpp"

int main()
{
	// -------------------- VALID CASES --------------------
	std::cout << "=== Valid Cases ===" << std::endl;
	try
	{
		Bureaucrat	b1("Alice", 1);
		Bureaucrat	b2("Bob", 150);
		Bureaucrat	b3("Charlie", 75);
		std::cout << b1;
		std::cout << b2;
		std::cout << b3;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Unexpected exception: " << e.what() << std::endl;
	}

	// -------------------- GRADE TOO HIGH --------------------
	std::cout << "\n=== Grade Too High ===" << std::endl;
	try
	{
		Bureaucrat	b("TooHigh", 0);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	// -------------------- GRADE TOO LOW --------------------
	std::cout << "\n=== Grade Too Low ===" << std::endl;
	try
	{
		Bureaucrat	b("TooLow", 151);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	// -------------------- INCREMENT AT LIMIT --------------------
	std::cout << "\n=== Increment at Grade 1 ===" << std::endl;
	try
	{
		Bureaucrat	b("TopGrade", 1);
		std::cout << b;
		b.incrementGrade();
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	// -------------------- DECREMENT AT LIMIT --------------------
	std::cout << "\n=== Decrement at Grade 150 ===" << std::endl;
	try
	{
		Bureaucrat	b("BottomGrade", 150);
		std::cout << b;
		b.decrementGrade();
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	// -------------------- INCREMENT / DECREMENT --------------------
	std::cout << "\n=== Normal Increment / Decrement ===" << std::endl;
	try
	{
		Bureaucrat	b("Dave", 50);
		std::cout << b;
		b.incrementGrade();
		std::cout << b;
		b.decrementGrade();
		b.decrementGrade();
		std::cout << b;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	// -------------------- COPY / ASSIGNMENT --------------------
	std::cout << "\n=== Copy / Assignment ===" << std::endl;
	try
	{
		Bureaucrat	b1("Eve", 10);
		Bureaucrat	b2(b1);
		Bureaucrat	b3("Temp", 99);
		b3 = b1;
		std::cout << b1;
		std::cout << b2;
		std::cout << b3;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	// -------------------- NO NAME CONSTRUCTORS --------------------
	std::cout << "\n=== No Name Constructors ===" << std::endl;

	// default constructor
	try
	{
		Bureaucrat	b;
		std::cout << b;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	// int-only constructor
	try
	{
		Bureaucrat	b(42);
		std::cout << b;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	// int-only constructor, grade too high
	try
	{
		Bureaucrat	b(0);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	// int-only constructor, grade too low
	try
	{
		Bureaucrat	b(151);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	// name-only constructor (defaults to grade 150)
	try
	{
		Bureaucrat	b("OnlyName");
		std::cout << b;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	return 0;
}