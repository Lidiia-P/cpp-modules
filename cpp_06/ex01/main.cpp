#include "Serializer.hpp"

int main(void)
{
	Data data;
	data.i = 42;
	data.d = 42.42;
	data.str = "chaos";

	std::cout << BLUE_B <<"originalPtr->i = " << RESET << data.i <<std::endl;
	std::cout << BLUE_B <<"originalPtr->d = " << RESET << data.d <<std::endl;
	std::cout << BLUE_B <<"originalPtr->str = "<< RESET << data.str <<std::endl;

	uintptr_t serialized = Serializer::serialize(&data);

	Data *restoredPtr = Serializer::deserialize(serialized);

	std::cout << "\nOriginal pointer : " << (&data == restoredPtr ? GREEN : RED) << &data << RESET << std::endl;
	std::cout << "Serialized value : " << serialized << std::endl;
	std::cout << "Restored pointer : " << (&data == restoredPtr ? GREEN : RED) << restoredPtr << RESET << std::endl;
	
	std::cout << MAGENTA << "\nrestoredPtr->i = " << RESET << restoredPtr->i << std::endl;
	std::cout << MAGENTA << "restoredPtr->d = " << RESET << restoredPtr->d << std::endl;
	std::cout << MAGENTA << "restoredPtr->str = " << RESET << restoredPtr->str << std::endl;

	// -----------Mismatch poiters----------
	Data fakeData;
	fakeData.i = 99;
	fakeData.d = 99.99;
	fakeData.str = "fake";

	uintptr_t fakeSerialied = Serializer::serialize(&fakeData);

	Data *mismatchPtr = Serializer::deserialize(fakeSerialied);

	std::cout << RED << "\n--- Mismatch test ---\n" << RESET;
	std::cout << "Original pointer (&data) : " << (&data == mismatchPtr ? GREEN : RED) << &data << RESET << std::endl;
	std::cout << "Serialized value (fakeSerialied): " << fakeSerialied << std::endl;
	std::cout << "Restored pointer (&data VS mismatchPtr) : " << (&data == mismatchPtr ? GREEN : RED) << mismatchPtr << RESET << std::endl;

	std::cout << "\nOriginal pointer (&fakeData) : " << (&fakeData == mismatchPtr ? GREEN : RED) << &fakeData << RESET << std::endl;
	std::cout << "Correct restored pointer (&fakeData VS mismatchPtr) : " << (&fakeData == mismatchPtr ? GREEN : RED) << mismatchPtr << RESET << std::endl;

	return 0;
}