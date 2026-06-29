#include "FileReplaser.hpp"

int main(int argc, char **argv) {
	if (argc != 4)
	{
		std::cerr << "Usage: ./replace filename s1 s2" << std::endl;
		return (1);
	}
	if (argv[2][0] == 0)
	{
		std::cerr << "Error: string to replace cannot be empty" << std::endl;
		return (1);
	}
	FileReplaser replace(argv[1], argv[2], argv[3]);
	replace.replaceAll();
	return (0);
}