#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()
{
	// -------------------- VALID FORM --------------------
	std::cout << "=== Valid Forms ===" << std::endl;
	try
	{
		Form	f1("TaxForm", 50, 25);
		Form	f2("FireForm", 1, 1);
		Form	f3("ShoeForm", 150, 150);
		std::cout << f1;
		std::cout << f2;
		std::cout << f3;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	// -------------------- FORM GRADE TOO HIGH --------------------
	std::cout << "\n=== Form Grade Too High ===" << std::endl;
	try
	{
		Form	f("BadForm", 0, 50);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	// -------------------- FORM GRADE TOO LOW --------------------
	std::cout << "\n=== Form Grade Too Low ===" << std::endl;
	try
	{
		Form	f("BadForm", 50, 151);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	// -------------------- BUREAUCRAT GRADE HIGH ENOUGH --------------------
	std::cout << "\n=== Bureaucrat Can Sign ===" << std::endl;
	try
	{
		Bureaucrat	b("Alice", 10);
		Form		f("TaxForm", 50, 25);
		std::cout << f;
		b.signForm(f);
		std::cout << f;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	// -------------------- BUREAUCRAT GRADE TOO LOW TO SIGN --------------------
	std::cout << "\n=== Bureaucrat Cannot Sign ===" << std::endl;
	try
	{
		Bureaucrat	b("Bob", 100);
		Form		f("TaxForm", 50, 25);
		std::cout << f;
		b.signForm(f);
		std::cout << f;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	// -------------------- SIGN ALREADY SIGNED FORM --------------------
	std::cout << "\n=== Sign Already Signed Form ===" << std::endl;
	try
	{
		Bureaucrat	b("Charlie", 1);
		Form		f("TaxForm", 50, 25);
		b.signForm(f);
		std::cout << f;
		b.signForm(f); // sign again
		std::cout << f;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	// -------------------- COPY FORM --------------------
	std::cout << "\n=== Copy Form ===" << std::endl;
	try
	{
		Bureaucrat	b("Dave", 1);
		Form		f1("ContractForm", 30, 10);
		b.signForm(f1);
		Form		f2(f1);						// copy constructor
		Form		f3("Temp", 99, 99);
		f3 = f1;								// assignment operator
		std::cout << f1;
		std::cout << f2;
		std::cout << f3;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	// -------------------- NO NAME CONSTRUCTORS --------------------
	std::cout << "\n=== No Name Constructors ===" << std::endl;
	try
	{
		Bureaucrat b;
		Form	f;
		std::cout << f;
		b.signForm(f);
		std::cout << f;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}