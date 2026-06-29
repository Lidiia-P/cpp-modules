#ifndef CLASS_INTERN_HPP
# define CLASS_INTERN_HPP
# include <iostream>
# include <string>
# include <exception>
# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"

class AForm;

class Intern {
	public:
		// Constractors
		Intern(void) = default;
		Intern(const Intern& other) = default;

		// Overloaded Operators
		Intern& operator=(const Intern&) { return *this; }

		// Deconstructor
		~Intern(void) = default;

		// Member function
		AForm *makeForm(std::string name, std::string target);
};

#endif