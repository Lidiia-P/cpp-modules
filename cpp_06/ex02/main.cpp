#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main(void)
{
	std::srand(std::time(NULL));

	for (int i = 0; i < 6; i++) {
		Base *obj = generate();
		std::cout << BLUE_B <<"Pointer:   " << RESET; identify(obj);
		std::cout << MAGENTA <<"Reference: " << RESET; identify(*obj);
		delete obj;
	}

	return 0;
}