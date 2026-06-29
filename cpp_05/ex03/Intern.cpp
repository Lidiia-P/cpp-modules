# include "Intern.hpp"

static AForm *createShrubbery(std::string target) {
	return new ShrubberyCreationForm(target);
}

static AForm *createRobotomy(std::string target) {
	return new RobotomyRequestForm(target);
}

static AForm *createPardon(std::string target) {
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string name, std::string target) {
	struct {
		std::string name;
		AForm *(*create)(std::string);
	}
	forms[] = {
		{ "shrubbery creation", createShrubbery},
		{ "robotomy request", createRobotomy},
		{ "presidential pardon", createPardon}
	};

	for (int i = 0; i < 3; i++)
	{
		if (forms[i].name == name)
		{
			std::cout << "Intern creates " << name << std::endl;
			return forms[i].create(target);
		}
	}
	std::cerr << "Error: " << name << " does not exist, try the following forms :\"shrubbery creation\", \"robotomy request\", \"presidential pardon\"" << std::endl;
	return NULL;
}
