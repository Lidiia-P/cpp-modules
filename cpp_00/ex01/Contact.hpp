#ifndef CLASS_CONTACT_HPP
# define CLASS_CONTACT_HPP
# include <iostream>
# include <iomanip>
# include <string>
# include "Contact.hpp"

class Contact {
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_num;
		std::string secret;

		std::string getShort(std::string origin);
		

	public:
		bool isEmpty();
		void setContact();
		void printContact();
		void printContactList(int index);
		Contact(void);
		~Contact(void);
	
};
#endif
