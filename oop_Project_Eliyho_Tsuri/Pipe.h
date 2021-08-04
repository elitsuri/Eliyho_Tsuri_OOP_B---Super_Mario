#pragma once
#include "StaticObject.h"
class Pipe: public StaticObject
{
public:
	Pipe(Vector2f pos)
	{
		m_pos = pos;
		m_sprite.setTextureRect(IntRect(2, 85, 32, 48));
	}
	virtual void draw(RenderWindow &window) { window.draw(m_sprite); }
	~Pipe() {}
};

