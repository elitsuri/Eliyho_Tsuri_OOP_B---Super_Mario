#pragma once
#include "StaticObject.h"
class Hill : public StaticObject
{
public:
	Hill(Vector2f pos)
	{
		m_sprite.setTextureRect(IntRect(0, 130, 50, 35));
		m_pos = pos;
	}
	virtual void draw(RenderWindow &window) { window.draw(m_sprite); }
	~Hill() {};
};

