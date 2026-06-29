#ifndef CLASS_ROBOTOMYREQUESTFORM_HPP
# define CLASS_ROBOTOMYREQUESTFORM_HPP
# include <iostream>
# include <string>
# include <cstdlib>
# include "AForm.hpp"

class RobotomyRequestForm : virtual public AForm {
	private:
		std::string	_target;
		//Member functions
		void beExecuted(void) const;

	public:
		// Constractors
		RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45), _target("DefaultTarget") {};
		RobotomyRequestForm(std::string	target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {};
		RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), _target(other._target) {};

		// Overloaded Operators
		RobotomyRequestForm& operator=(const RobotomyRequestForm &other);

		// Deconstructor
		~RobotomyRequestForm(void) = default;
};

#endif