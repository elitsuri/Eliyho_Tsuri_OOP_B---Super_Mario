#pragma once
#include <map>
#include "Mario.h"
#include "Goomba.h"
#include "Turtle.h"
#include "Coin.h"
#include "Box.h"
#include "Brick.h"
#include "Pipe.h"
#include "Wall.h"
#include "Castle.h"
class GameObject;
class Colission
{
public:
	Colission() {};
	~Colission() {};
	void processCollision(GameObject& object1, GameObject& object2);
};