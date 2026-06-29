#ifndef CLASS_WEAPON_HPP
# define CLASS_WEAPON_HPP
# include <iostream>
# include <string>


class Weapon {
	private: 
		std::string type;
	public:
		Weapon(const std::string& type);
		~Weapon(void);
		const std::string& getType(void); // returns type by const reference
		void setType(const std::string& newType); // modifies type
};


#endif