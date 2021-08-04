#pragma once
#include "StaticObject.h"
class Coin: public StaticObject
{
public:
	Coin(Vector2f pos)
	{
		m_sprite.setTextureRect(IntRect(77, 112, 16, 16));
		m_pos = pos;
	}
	virtual void draw(RenderWindow &window) { window.draw(m_sprite); }
	~Coin() {};
};

