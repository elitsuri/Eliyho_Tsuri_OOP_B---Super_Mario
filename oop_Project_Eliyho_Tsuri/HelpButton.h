#pragma once
#include "Button.h"

class HelpButton :public Button
{
public:
	HelpButton();
	virtual void ClickOn(Vector2f pos, RenderWindow &win, bool & flag, const char run);
	virtual Sprite getSprite() { return m_sprite; }
	virtual void moveOn(Vector2f pos);
	~HelpButton() {};
private:
	bool m_button_help;
};