/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lperekhr <lperekhr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/12/11 11:21:11 by lperekhr      #+#    #+#                 */
/*   Updated: 2025/12/11 14:04:18 by lperekhr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

static const char* RED = "\033[31m";
static const char* RESET = "\033[0m";

static std::string getInfo(std::string message) {
	
	std::string	info;
	std::cout << message << std::endl;

	while (true)
	{
		if (!std::getline(std::cin, info))
		{
			std::cout << RED << "Invalid input" << RESET << std::endl;
			return ("");
		}
		if (!info.empty())
		{
			if (!message.compare("Enter phone number:"))
			{
				for (int i = 0; i < (int)info.length(); i++)
				{
					if (!isdigit(info[i]))
					{
						std::cout << RED << "Non-digit input" << RESET << std::endl;
						info.clear();
						break;
					}
				}
				if (info.empty())
					continue;
			}
			return (info);
		}
		else
			std::cout << RED << "Empty field" << RESET << std::endl;
	}
}

void Contact:: setContact() {
	first_name = getInfo("Enter first name:");
	if (first_name.empty())
		return;
	last_name = getInfo("Enter last name:");
	if (last_name.empty())
		return;
	nickname = getInfo("Enter nickname:");
	if (nickname.empty())
		return;
	phone_num = getInfo("Enter phone number:");
	if (phone_num.empty())
		return;
	secret = getInfo("Enter darkest secret:");
	if (secret.empty())
		return;
}

void Contact:: printContactList(int index) {
	char separator = '|';

	std::cout
			<< std::setw(10) << index << separator
			<< std::setw(10) << getShort(first_name) << separator
			<< std::setw(10) << getShort(last_name) << separator
			<< std::setw(10) << getShort(nickname) 
	<< std::endl;
}

std::string Contact:: getShort(std::string origin) {
	std::string temp;

	if (origin.length() >= 10)
	{
		temp = origin.substr(0, 9);
		temp += ".";
		return (temp);
	}
	else
		return (origin);
}

void Contact:: printContact() {

	std::cout
			<< "First name: " << first_name << std::endl
			<< "Last name: " << last_name << std::endl
			<< "Nickname: " << nickname << std::endl
			<< "Phone number: " << phone_num << std::endl
			<< "Darkest secret: " << secret << std::endl;
}

bool Contact::isEmpty() {
	return first_name.empty()
		&& last_name.empty()
		&& nickname.empty()
		&& phone_num.empty()
		&& secret.empty();
}

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}
