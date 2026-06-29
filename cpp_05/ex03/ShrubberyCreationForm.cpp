#include "ShrubberyCreationForm.hpp"
// -------------------- MEMBER FUNCTIONS --------------------

void ShrubberyCreationForm::beExecuted(void) const {
	std::ofstream	file;

	file.open((_target + "_shrubbery").c_str());
	if (file.fail())
	{
		std::cout << "Couldn't open output file" << std::endl;
		return ;
	}
	file << TREE;
	file.close();
	std::cout << "A shrubbery is successfully created" << std::endl;
}


// -------------------- OPERATORS ------------------
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;	
	}
	return (*this);
}

std::ostream &operator<<(std::ostream &os, ShrubberyCreationForm const &form)
{
	return (os << form.getName() << " form, "
			<< (form.getIsSigned() ? "signed" : "not signed")
			<< ", grade to sign: " << form.getSignGrade()
			<< ", grade to execute: " << form.getExeGrade()
			<< "\n");
}