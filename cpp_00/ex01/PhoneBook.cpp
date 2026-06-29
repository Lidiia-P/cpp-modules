/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lperekhr <lperekhr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/12/11 11:21:35 by lperekhr      #+#    #+#                 */
/*   Updated: 2025/12/11 14:05:18 by lperekhr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

static const char* RED = "\033[31m";
static const char* YELLOW = "\033[33m";
static const char* BLUE = "\033[34m";
static const char* RESET = "\033[0m";

int PhoneBook:: newContact(int index)
{
	std::cout << YELLOW << "\nAdding..." << RESET << std::endl;
	contact[index].setContact();
	index++;
	if (index == 8)
		index = 0;
	return (index);
}

static void printHeader()
{
	char separator = '|';
	std::string title;

	title = "THE CURRENT LIST OF CONTACTS:\n\n";
	std::cout
			<< BLUE << title << RESET
			<< std::setw(10) << "INDEX" << separator
			<< std::setw(10) << "FIRST NAME" << separator
			<< std::setw(10) << "LAST NAME" << separator
			<< std::setw(10) << "NICKNAME" 
	<< std::endl;
}

void PhoneBook:: printBook()
{
	if (contact[0].isEmpty())
		std::cout << BLUE << "\nPhonebook is empty:" << RESET << std::endl;
	else
	{	printHeader();
		for (int i = 0; i < 8; i++)
			contact[i].printContactList(i);
		getContactInfo();
	}
}

void PhoneBook::getContactInfo()
{
	std::string chosen;
	int index;

	std::cout << "Enter index:" << std::endl;
	while (true)
	{
		if (!std::getline(std::cin, chosen))
		{
			std::cout << RED << "Invalid input" << RESET << std::endl;
			return ;
		}	
		if (chosen.empty() || chosen.length() != 1 || chosen[0] < '0' || chosen[0] > '7')
		{
			std::cout << RED << "Invalid index, try with 0-7" << RESET << std::endl;
			chosen.clear();
			continue ;
		}
		else
		{
			std::istringstream(chosen) >> index;
			contact[index].printContact();
			break ;
		}
	}
}

PhoneBook::PhoneBook() {
}

PhoneBook::~PhoneBook() {
}