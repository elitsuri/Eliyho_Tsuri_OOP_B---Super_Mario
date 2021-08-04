#pragma once
#include "StaticObject.h"
class Box :public StaticObject
{
public:
	Box(Vector2f pos)
	{
		m_sprite.setTextureRect(IntRect(127, 112, 16, 16));
		m_pos = pos;
	}
	virtual void draw(RenderWindow &window) { window.draw(m_sprite); }
	~Box() {};
};

