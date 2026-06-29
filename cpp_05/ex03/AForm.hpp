#ifndef CLASS_AFORM_HPP
# define CLASS_AFORM_HPP
# include <iostream>
# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private: 
		const std::string	_name;
		bool				_isSigned;
		int			_signGrade;
		int			_exeGrade;

	public:
		// Constractors
		AForm(void) : _name("DefaultAForm"), _isSigned(false), _signGrade(150), _exeGrade(150) {};
		AForm(std::string name, const int signGrade, const int exeGrade);
		AForm(const AForm& other) : _name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade), _exeGrade(other._exeGrade) {};

		// Overloaded Operators
		AForm& operator=(const AForm& other);

		// Deconstructor
		virtual ~AForm(void) = default;

		// Member functions
		void	beSigned(Bureaucrat &bureaucrat);
		std::string	getName() const {return _name;};
		bool	getIsSigned() const {return _isSigned;}
		int		getSignGrade() const {return _signGrade;};
		int		getExeGrade() const {return _exeGrade;};
		void	execute(Bureaucrat const & executor) const;
		
		// Pure virtual function
		virtual void beExecuted(void) const = 0;

		// Exceptions
		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class FormNotSingedException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};
std::ostream& operator<<(std::ostream& os, const AForm& b);

#endif