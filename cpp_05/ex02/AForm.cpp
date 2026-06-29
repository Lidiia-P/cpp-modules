# include "AForm.hpp"

// -------------------- EXEPTIONS --------------------

const char *AForm::GradeTooHighException::what() const throw() {
	return ("Grade too high!");
}

const char *AForm::GradeTooLowException::what() const throw() {
	return ("Grade too low!");
};

const char *AForm::FormNotSingedException::what() const throw() {
	return ("Form not signed!");
};

// -------------------- MEMBER FUNCTIONS --------------------

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= _signGrade)
		_isSigned = true;
	else
		throw GradeTooLowException();
}

void	AForm::execute(Bureaucrat const &executor) const {
	if (!this->_isSigned)
		throw FormNotSingedException();
	if (executor.getGrade() < this->getExeGrade())
		this->beExecuted();
	else
		throw GradeTooLowException();
}


// -------------------- CONSTRUCTORS ------------------
AForm::AForm(std::string name, const int signGrade, const int exeGrade) : _name(name), _isSigned(false) {
	if (signGrade < 1 || exeGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || exeGrade > 150)
		throw GradeTooLowException();
	_signGrade = signGrade;
	_exeGrade = exeGrade;
}

// -------------------- OPERATORS ------------------
AForm& AForm::operator=(const AForm& other) {
	if (this != &other)
	{
		_isSigned = other._isSigned;
		_signGrade = other._signGrade;
		_exeGrade = other._exeGrade;
	}	
	return (*this);
}

std::ostream &operator<<(std::ostream &os, AForm const &form)
{
	return (os << form.getName() << " form, "
			<< (form.getIsSigned() ? "signed" : "not signed")
			<< ", grade to sign: " << form.getSignGrade()
			<< ", grade to execute: " << form.getExeGrade()
			<< "\n");
}