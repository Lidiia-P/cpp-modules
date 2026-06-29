# include "Form.hpp"

// -------------------- EXEPTIONS --------------------

const char *Form::GradeTooHighException::what() const throw() {
	return ("Grade too high!");
}

const char *Form::GradeTooLowException::what() const throw() {
	return ("Grade too low!");
}

// -------------------- MEMBER FUNCTIONS --------------------

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= _signGrade)
		_isSigned = true;
	else
		throw GradeTooLowException();
}

// -------------------- CONSTRUCTORS ------------------
Form::Form(std::string name, const int signGrade, const int exeGrade) : _name(name), _isSigned(false) {
	if (signGrade < 1 || exeGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || exeGrade > 150)
		throw GradeTooLowException();
	_signGrade = signGrade;
	_exeGrade = exeGrade;
}

// -------------------- OPERATORS ------------------
Form& Form::operator=(const Form& other) {
	if (this != &other)
	{
		_isSigned = other._isSigned;
		_signGrade = other._signGrade;
		_exeGrade = other._exeGrade;
	}	
	return (*this);
}

std::ostream &operator<<(std::ostream &os, Form const &form)
{
	return (os << form.getName() << " form, "
			<< (form.getIsSigned() ? "signed" : "not signed")
			<< ", grade to sign: " << form.getSignGrade()
			<< ", grade to execute: " << form.getExeGrade()
			<< "\n");
}