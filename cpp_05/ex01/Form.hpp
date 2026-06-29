#ifndef CLASS_FORM_HPP
# define CLASS_FORM_HPP
# include <iostream>
# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private: 
		const std::string	_name;
		bool				_isSigned;
		int			_signGrade;
		int			_exeGrade;

	public:
		// Constractors
		Form(void) : _name("DefaultForm"), _isSigned(false), _signGrade(150), _exeGrade(150) {};
		Form(std::string name, const int signGrade, const int exeGrade);
		Form(const Form& other) : _name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade), _exeGrade(other._exeGrade) {};

		// Overloaded Operators
		Form& operator=(const Form& other);

		// Deconstructor
		~Form(void) = default;

		// Member functions
		void	beSigned(Bureaucrat &bureaucrat);
		std::string	getName() const {return _name;};
		bool	getIsSigned() const {return _isSigned;}
		int		getSignGrade() const {return _signGrade;};
		int		getExeGrade() const {return _exeGrade;};

		// Exceptions
		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};
std::ostream& operator<<(std::ostream& os, const Form& b);

#endif