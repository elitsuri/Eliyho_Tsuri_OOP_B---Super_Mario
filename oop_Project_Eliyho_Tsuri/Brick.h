#pragma once
#include "StaticObject.h"

class Brick: public StaticObject
{
public:
	Brick(Vector2f pos)
	{
		m_pos = pos;
		m_sprite.setTextureRect(IntRect(143, 112, 16, 16));
	}
	virtual void draw(RenderWindow &window) { window.draw(m_sprite); }
	~Brick() {};
};

