#pragma once
#include "StaticObject.h"
class Castle: public StaticObject
{
public:
	Castle(Vector2f pos)
	{
		m_sprite.setTextureRect(IntRect(95, 0, 145, 110));
		m_sprite.setScale(1.7f, 1.7f);
		m_pos = pos;
	}
	virtual void draw(RenderWindow &window) { window.draw(m_sprite); }
	~Castle() {};
};