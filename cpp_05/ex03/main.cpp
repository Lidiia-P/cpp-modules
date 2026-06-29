#include <cstdlib>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main()
{
	std::srand(std::time(NULL));

	// -------------------- INTERN CREATES FORMS --------------------
	std::cout << "=== Intern Creates Forms ===" << std::endl;
	Intern intern;
	AForm *shrubbery = intern.makeForm("shrubbery creation", "garden");
	AForm *robotomy  = intern.makeForm("robotomy request", "Dave");
	AForm *pardon    = intern.makeForm("presidential pardon", "criminal");

	std::cout << *shrubbery;
	std::cout << *robotomy;
	std::cout << *pardon;

	// -------------------- UNKNOWN FORM --------------------
	std::cout << "\n=== Unknown Form ===" << std::endl;
	AForm *unknown = intern.makeForm("coffee form", "target");
	if (!unknown)
		std::cout << "Returned nullptr as expected" << std::endl;

	// -------------------- SHRUBBERY --------------------
	std::cout << "\n=== ShrubberyCreationForm ===" << std::endl;
	try
	{
		Bureaucrat b("Alice", 1);
		b.signForm(*shrubbery);
		b.executeForm(*shrubbery);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	// -------------------- ROBOTOMY --------------------
	std::cout << "\n=== RobotomyRequestForm ===" << std::endl;
	try
	{
		Bureaucrat b("Bob", 1);
		b.signForm(*robotomy);
		b.executeForm(*robotomy);
		b.executeForm(*robotomy);
		b.executeForm(*robotomy);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	// -------------------- PARDON --------------------
	std::cout << "\n=== PresidentialPardonForm ===" << std::endl;
	try
	{
		Bureaucrat b("Charlie", 1);
		b.signForm(*pardon);
		b.executeForm(*pardon);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	// -------------------- EXECUTE UNSIGNED --------------------
	std::cout << "\n=== Execute Unsigned Form ===" << std::endl;
	try
	{
		Bureaucrat b("Dave", 1);
		AForm *f = intern.makeForm("robotomy request", "target");
		b.executeForm(*f);
		delete f;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	// -------------------- GRADE TOO LOW --------------------
	std::cout << "\n=== Grade Too Low ===" << std::endl;
	try
	{
		Bureaucrat signer("Signer", 1);
		Bureaucrat executor("Executor", 150);
		AForm *f = intern.makeForm("presidential pardon", "target");
		signer.signForm(*f);
		executor.executeForm(*f);
		delete f;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	// -------------------- CLEANUP --------------------
	delete shrubbery;
	delete robotomy;
	delete pardon;

	return 0;
}