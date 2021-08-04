#pragma once
#include "DynamicObject.h"
class Mario : public DynamicObject
{
public:
	Mario();
	~Mario() {};
	virtual void move(vector <string> &map, float time, float offsetX, float offsetY);
	virtual void Collision(int num, vector <string> &map);
	virtual void setPos(float val, Direction dir, bool onGround);
	virtual void set(int x, int y) {};
	bool getWin() { return m_win; }
	int point = 0;
private:
	bool m_win = false;
	bool reloadPlay = true;
	Music m_coin;
};