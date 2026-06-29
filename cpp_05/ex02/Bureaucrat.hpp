#ifndef CLASS_BUREAUCRAT_HPP
# define CLASS_BUREAUCRAT_HPP
# include <iostream>
# include <string>
# include <exception>
# include "AForm.hpp"

class AForm;

class Bureaucrat {
	private: 
		const std::string	_name;
		int	_grade;

	public:
		// Constractors
		Bureaucrat(void) : _name("Default"), _grade(150) {};
		Bureaucrat(std::string	name) : _name(name), _grade(150) {};
		Bureaucrat(int	grade);
		Bureaucrat(std::string	name, int	grade);
		Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {};

		// Overloaded Operators
		Bureaucrat& operator=(const Bureaucrat& other);

		// Deconstructor
		~Bureaucrat(void) = default;

		// Member functions
		std::string getName() const {return _name;};
		int		getGrade() const {return _grade;};
		void	incrementGrade();
		void	decrementGrade();
		void	signForm(AForm &form);
		void	executeForm(AForm const & form) const;

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
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif