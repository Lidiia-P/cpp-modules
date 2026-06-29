#ifndef CLASS_SHRUBBERYCREATIONFORM_HPP
# define CLASS_SHRUBBERYCREATIONFORM_HPP
# include <iostream>
# include <string>
# include <fstream>
# include "AForm.hpp"
# define TREE \
"                     *\n" \
"                    ***\n" \
"                   *****\n" \
"                  *******\n" \
"                 *********\n" \
"                ***********\n" \
"               *************\n" \
"              ***************\n" \
"             *****************\n" \
"                    |||\n" \
"                    |||\n" \
"                    |||\n\n"

class ShrubberyCreationForm : virtual public AForm {
	private:
		std::string	_target;
		//Member functions
		void beExecuted(void) const;

	public:
		// Constractors
		ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137), _target("DefaultTarget") {};
		ShrubberyCreationForm(std::string	target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {};
		ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), _target(other._target) {};

		// Overloaded Operators
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm &other);

		// Deconstructor
		~ShrubberyCreationForm(void) = default;
};

#endif