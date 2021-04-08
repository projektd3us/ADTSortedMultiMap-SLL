#include <iostream>
#include "ShortTest.h"
#include "ExtendedTest.h"


// takes 10:59 to compile testRelations();
int main() {
	testAll();
	testAllExtended();

	std::cout << "Finished SMM Tests!" << std::endl;
	system("pause");
}
