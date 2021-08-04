#pragma once
#include <SFML/Audio.hpp>
#include "Resources.h"

class Button
{
public:
	Button() 
	{ 
		m_sprite = Resources::get().get_sprite(1); 
		m_sound.openFromFile("files/sound/select.ogg");
	}
	virtual void ClickOn(Vector2f pos, RenderWindow &win, bool & flag, const char run) = 0;
	virtual void draw(RenderWindow & window) { window.draw(m_sprite); }
	virtual Sprite getSprite() = 0;
	virtual void moveOn(Vector2f pos) = 0;
	virtual ~Button() {};
protected:
	Sprite m_sprite;
	Sprite m_button_on;
	Sprite m_button_before;
	Music m_sound;
};