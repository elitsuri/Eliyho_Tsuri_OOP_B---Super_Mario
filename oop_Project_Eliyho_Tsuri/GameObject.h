#pragma once
#include "Resources.h"
#include <SFML/Audio.hpp>
const int WIDTH = 50;
const int HIEGHT = 50;

class GameObject
{
public:
	GameObject()
	{
		m_sprite = Resources::get().get_sprite(2);
		m_sprite.setScale(1.5f, 1.5f);
	}
	virtual ~GameObject() {};
	virtual void draw(RenderWindow& window) { window.draw(m_sprite); }
	Sprite getSprite() { return m_sprite; }
protected:
	Vector2f m_pos;
	Sprite m_sprite;
};