#pragma once
#include "StaticObject.h"
class Cloud: public StaticObject
{
public:
	Cloud(Vector2f pos)
	{
		m_sprite.setTextureRect(IntRect(99, 224, 41, 31));
		m_pos = pos;
	}
	virtual void draw(RenderWindow &window) { window.draw(m_sprite); }
	~Cloud() {};
};

