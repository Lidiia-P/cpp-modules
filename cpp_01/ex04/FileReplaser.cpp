#include "FileReplaser.hpp"

void FileReplaser::replaceAll(){
	std::ifstream infile(filename);
	if (!infile.is_open())
	{
		std::cerr << "Error: cannot open file '" << filename << "'" << std::endl;
		exit(1);
	}
	std::ofstream outfile(std::string(filename) + ".replace");
	if (!outfile.is_open())
	{
		std::cerr << "Error: creating output file" << std::endl;
		exit(1);
	}
	std::string line;
	while (std::getline(infile, line))
	{
		size_t pos = 0;
		while((pos = line.find(s1, pos)) != std::string::npos)
		{
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos += s2.length();
		}
		outfile << line << "\n";
	}
}

FileReplaser::FileReplaser(std::string filename, std::string s1, std::string s2) 
			: filename(filename), s1(s1), s2(s2) {
}

FileReplaser::~FileReplaser(void) {
}