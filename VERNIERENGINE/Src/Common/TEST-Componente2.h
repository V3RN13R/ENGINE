#include "Component.h"
#include <iostream>

class TESTComponente2 : public Component {

public:
	TESTComponente2() {}
	virtual ~TESTComponente2() {}

	virtual void update() {
		std::cout << "2 \n";
	}

private:

};