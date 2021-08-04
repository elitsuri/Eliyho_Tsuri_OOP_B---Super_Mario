#pragma once
#include "StaticObject.h"
class Bush : public StaticObject
{
public:
	Bush(Vector2f pos)
	{
		m_sprite.setTextureRect(IntRect(161, 120, 70, 23));
		m_pos = pos;
	}
	virtual void draw(RenderWindow &window) { window.draw(m_sprite); }
	~Bush() {};
};

