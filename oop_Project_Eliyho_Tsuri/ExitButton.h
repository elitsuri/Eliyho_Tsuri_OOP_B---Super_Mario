#pragma once
#include "Button.h"

class ExitButton :public Button
{
public:
	ExitButton();
	virtual void ClickOn(Vector2f pos, RenderWindow &win, bool & flag, const char run);
	virtual Sprite getSprite() { return m_sprite; }
	virtual void moveOn(Vector2f pos);
	~ExitButton() {};
};