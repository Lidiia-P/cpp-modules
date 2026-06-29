# include "PresidentialPardonForm.hpp"

// -------------------- MEMBER FUNCTIONS --------------------

void PresidentialPardonForm::beExecuted(void) const {
	std::cout << "Informs that "<< _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}


// -------------------- OPERATORS ------------------
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;	
	}
	return (*this);
}

std::ostream &operator<<(std::ostream &os, PresidentialPardonForm const &form)
{
	return (os << form.getName() << " form, "
			<< (form.getIsSigned() ? "signed" : "not signed")
			<< ", grade to sign: " << form.getSignGrade()
			<< ", grade to execute: " << form.getExeGrade()
			<< "\n");
}