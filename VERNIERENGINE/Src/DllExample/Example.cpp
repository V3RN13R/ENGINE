#include "Example.h"
#include <iostream>
Example::Example()
{
	std::cout << "Constructor de una clase desde dll\n";
}

extern "C" {
	EXAMPLE_API void example() {
		std::cout << "Metodo desde una dll\n";
		Example();
	}
}
