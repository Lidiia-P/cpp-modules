#include "RobotomyRequestForm.hpp"

// -------------------- MEMBER FUNCTIONS --------------------

void RobotomyRequestForm::beExecuted(void) const {
	srand((unsigned) time(NULL));
	std::cout << "Bzzzz Bzzzz Bzzzz" << std::endl;
	if (rand() % 2)
		std::cout << "Informs that "
				<< _target 
				<< " has been robotomized successfully" 
				<< std::endl;
	else
		std::cout << "Informs that "
				<< _target 
				<< "'s robotomization failed" 
				<< std::endl;
}


// -------------------- OPERATORS ------------------
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;	
	}
	return (*this);
}

std::ostream &operator<<(std::ostream &os, RobotomyRequestForm const &form)
{
	return (os << form.getName() << " form, "
			<< (form.getIsSigned() ? "signed" : "not signed")
			<< ", grade to sign: " << form.getSignGrade()
			<< ", grade to execute: " << form.getExeGrade()
			<< "\n");
}