#ifndef CLASS_PRESIDENTIALPARDONFORM_HPP
# define CLASS_PRESIDENTIALPARDONFORM_HPP
# include <iostream>
# include <string>
# include <exception>
# include "AForm.hpp"

class PresidentialPardonForm : virtual public AForm {
	private:
		std::string	_target;
		//Member functions
		void beExecuted(void) const;

	public:
		// Constractors
		PresidentialPardonForm(void) : AForm("PresidentialPardonForm", 25, 5), _target("DefaultTarget") {};
		PresidentialPardonForm(std::string	target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {};
		PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other), _target(other._target) {};

		// Overloaded Operators
		PresidentialPardonForm& operator=(const PresidentialPardonForm &other);

		// Deconstructor
		~PresidentialPardonForm(void) = default;
};

std::ostream &operator<<(std::ostream &os, PresidentialPardonForm const &form);

#endif