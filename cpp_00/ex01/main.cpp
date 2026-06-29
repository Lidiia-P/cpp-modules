/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lperekhr <lperekhr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/12/11 11:21:30 by lperekhr      #+#    #+#                 */
/*   Updated: 2025/12/11 13:00:24 by lperekhr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.hpp"

static const char* BLUE = "\033[34m";
static const char* RESET = "\033[0m";

int	main(void)
{
	PhoneBook phonebook;
	std::string action;
	int index = 0;

	std::cout << BLUE << "My awesome phonebook!" << RESET <<std::endl;
	
	while (action.compare("EXIT"))
	{
		if (std::cin.eof())
				break;
		std::cout << "\nEnter one of the options:\n- ADD\n- SEARCH\n- EXIT" << std::endl;
		getline(std::cin, action);
		if (!action.compare("ADD"))
		{
			index = phonebook.newContact(index);
		}
		if (!action.compare("SEARCH"))
		{
			phonebook.printBook();
		}
	}
	return 0;
}
