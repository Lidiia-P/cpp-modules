#ifndef CLASS_FILEREPLASER_HPP
# define CLASS_FILEREPLASER_HPP
# include <iostream>
# include <string>
#include <fstream>

class FileReplaser {
	private: 
		std::string filename;
		std::string s1;
		std::string s2;
	public:
		FileReplaser(std::string filename, std::string s1, std::string s2);
		~FileReplaser(void);
		void replaceAll();
};

#endif