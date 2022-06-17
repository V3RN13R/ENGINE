#include "UIElement.h"
#include <string>
#include "../Common/Vector3D.h"

#include "LuaManager.h"

namespace Ogre {
	class TextAreaOverlayElement;
}

class UIText : public UIElement
{
public:
	UIText(std::string overlayName, std::string fontName, int fontSize, int order, std::string text, int rT, int gT, int bT, int rD, int gD, int bD, int x, int y);
	~UIText() 
	{
		if (_a == 1) 
			lua_close(state);
		state = nullptr;
	}

	//Im pretty sure size is based on font for text
	virtual void setPosition(int x, int y);
	virtual void setSize(int w, int h);

	void setFont(std::string fontName);
	void setFontSize(int newSize);
	void setText(std::string newText);
	void setTextColor(int r, int g, int b);

	virtual std::pair<int, int> getSize();

private:
	lua_State* state;
	int _a = 0;
	Ogre::TextAreaOverlayElement* _txt;
};