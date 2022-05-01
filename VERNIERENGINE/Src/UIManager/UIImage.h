#include "UIElement.h"

class UIImage : public UIElement {
	
private:
	std::string _name;
public:
	UIImage(std::string name, int order, std::string image);
	~UIImage() {}

	void show();

	std::string getName() { return _name; }
	Ogre::Overlay* getOverlay() { return _overlay; }
};