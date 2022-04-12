#include "UIManager.h"
#include "RenderMain.h"
#include <DefaultResourceProvider.h>

void UIManager::init(const std::string& resourceDirectory) {
	if (m_renderer == nullptr) {
		m_renderer = RenderMain::getInstance()->getRenderWindow();

		//CEGUI::DefaultResourceProvider* rp = static_cast<CEGUI::DefaultResourceProvider*>(CEGUI::System::getSingleton().getResourceProvider());
	}
}