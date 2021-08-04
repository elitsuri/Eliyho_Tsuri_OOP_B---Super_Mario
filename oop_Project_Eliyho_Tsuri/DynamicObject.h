#pragma once
#include "GameObject.h"
#include "Level.h"

class DynamicObject : public GameObject
{
public:
	DynamicObject() {};
	~DynamicObject() {};
	virtual void move(vector <string> &map, float time, float offsetX, float offsetY) = 0;
	virtual void set(int x, int y) = 0;
	virtual void Collision(int num, vector <string> &map) = 0;
	virtual void setPos(float val, Direction dir, bool Ground) = 0;
	int getPower() { return m_power; }
	Vector2f getPos() { return m_pos; }
	void setPower(int power) { m_power = m_power; }
	bool getLife() { return m_life; }
	void setLife(bool life) { m_life = life; }
	bool getGround() { return m_onGround; }
	Direction getDirect() { return m_direction; }
	float getFrame() { return m_frame; }
	FloatRect getRect() { return m_rect; }
protected:
	Direction m_direction;
	FloatRect m_rect;
	bool m_onGround;
	float m_frame;
	int m_power;
	bool m_life;
};