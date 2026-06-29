#include <cstdlib>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	std::srand(std::time(NULL));

	// -------------------- SHRUBBERY CREATION FORM --------------------
	std::cout << "=== ShrubberyCreationForm ===" << std::endl;

	// valid sign and execute
	try
	{
		Bureaucrat b("Alice", 1);
		ShrubberyCreationForm f("garden");
		std::cout << f;
		b.signForm(f);
		b.executeForm(f);
		std::cout << "Check 'garden_shrubbery' file was created" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	// execute without signing
	try
	{
		Bureaucrat b("Bob", 1);
		ShrubberyCreationForm f("garden2");
		b.executeForm(f);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	// grade too low to execute
	try
	{
		Bureaucrat signer("Signer", 1);
		Bureaucrat executor("Executor", 138);
		ShrubberyCreationForm f("garden3");
		signer.signForm(f);
		executor.executeForm(f);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	// -------------------- ROBOTOMY REQUEST FORM --------------------
	std::cout << "\n=== RobotomyRequestForm ===" << std::endl;

	// valid sign and execute (50% success rate, run a few times)
	try
	{
		Bureaucrat b("Charlie", 1);
		RobotomyRequestForm f("Dave");
		std::cout << f;
		b.signForm(f);
		b.executeForm(f);
		b.executeForm(f);
		b.executeForm(f);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	// execute without signing
	try
	{
		Bureaucrat b("Charlie", 1);
		RobotomyRequestForm f("Dave2");
		b.executeForm(f);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	// grade too low to execute
	try
	{
		Bureaucrat signer("Signer", 1);
		Bureaucrat executor("Executor", 46);
		RobotomyRequestForm f("Dave3");
		signer.signForm(f);
		executor.executeForm(f);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	// -------------------- PRESIDENTIAL PARDON FORM --------------------
	std::cout << "\n=== PresidentialPardonForm ===" << std::endl;

	// valid sign and execute
	try
	{
		Bureaucrat b("Eve", 1);
		PresidentialPardonForm f("criminal");
		std::cout << f;
		b.signForm(f);
		b.executeForm(f);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	// execute without signing
	try
	{
		Bureaucrat b("Eve", 1);
		PresidentialPardonForm f("criminal2");
		b.executeForm(f);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	// grade too low to execute
	try
	{
		Bureaucrat signer("Signer", 1);
		Bureaucrat executor("Executor", 6);
		PresidentialPardonForm f("criminal3");
		signer.signForm(f);
		executor.executeForm(f);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	// -------------------- GRADE TOO LOW TO SIGN --------------------
	std::cout << "\n=== Grade Too Low To Sign ===" << std::endl;
	try
	{
		Bureaucrat b("Frank", 150);
		ShrubberyCreationForm f("park");
		b.signForm(f);
		b.executeForm(f);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}