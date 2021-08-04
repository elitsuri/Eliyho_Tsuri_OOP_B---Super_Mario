#pragma once
#include "StaticObject.h"
class Wall :public StaticObject
{
public:
	Wall(Vector2f pos)
	{
		m_sprite.setTextureRect(IntRect(111, 112, 16, 16));
		m_pos = pos;
	}
	virtual void draw(RenderWindow &window) { window.draw(m_sprite); }
	~Wall() {};
};