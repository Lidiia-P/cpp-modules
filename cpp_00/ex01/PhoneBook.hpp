#ifndef CLASS_PHONEBOOK_H
# define CLASS_PHONEBOOK_H
# include <iostream>
# include <iomanip>
# include <string>
#include <sstream>
# include "Contact.hpp"

class PhoneBook {
	private: 
		Contact contact[8];
		void printContact();
		void getContactInfo();

	public:
		int newContact(int index);
		void printBook();

		PhoneBook(void);
		~PhoneBook(void);
};

#endif