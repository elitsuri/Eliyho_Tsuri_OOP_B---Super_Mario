#pragma once
#include "Enemy.h"
class Turtle: public Enemy
{
public:
	Turtle();
	~Turtle() {};
	virtual void set(int x, int y);
	virtual void move(vector <string> &map, float time, float offsetX, float offsetY);
	virtual void Collision(int num, vector <string> &map);
	virtual void setPos(float val, Direction dirct, bool onGround);
};