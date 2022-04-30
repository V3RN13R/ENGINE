#include "UIElement.h"

class UIImage : public UIElement {

public:
	UIImage(std::string name, std::string order, std::string image);
	~UIImage() {}
};