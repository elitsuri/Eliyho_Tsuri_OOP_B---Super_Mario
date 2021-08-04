#pragma once
#include "Button.h"
#include "Controller.h"
class StartButton :public Button
{
public:
	StartButton();
	virtual void ClickOn(Vector2f pos, RenderWindow &win, bool & flag, const char run_game);
	virtual Sprite getSprite() { return m_sprite; }
	virtual void moveOn(Vector2f pos);
	~StartButton() {};
private:
	Controller game;
};