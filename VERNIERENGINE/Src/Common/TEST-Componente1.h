#include "Component.h"
#include <iostream>

class TESTComponente1 : public Component {

public:
	TESTComponente1() {}
	virtual ~TESTComponente1() {}

	virtual void update() {
		std::cout << "1 \n";
	}

private:

};