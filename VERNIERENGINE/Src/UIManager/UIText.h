#include "UIElement.h"
#include <string>
#include "../Common/Vector3D.h"
namespace Ogre {
	class TextAreaOverlayElement;
}

class UIText : public UIElement
{
public:
	UIText(std::string overlayName, std::string fontName, int fontSize, int order, std::string text, int r, int g, int b, int x, int y);
	~UIText() {}

	//Im pretty sure size is based on font for text
	virtual void setPosition(int x, int y);
	virtual void setSize(int w, int h);

	void setFont(std::string fontName);
	void setFontSize(int newSize);
	void setText(std::string newText);
	void setTextColor(int r, int g, int b);

	virtual std::pair<int, int> getSize();

private:
	Ogre::TextAreaOverlayElement* _txt;
};