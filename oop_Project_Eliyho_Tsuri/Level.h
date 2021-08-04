#pragma once
#include <fstream>
#include "StaticObject.h"
const int H = 22;
const int W = 463;
using namespace std;
enum Direction { stop, go_left, go_right, go_up };

class Level
{
public:
	Level() {}
	Level(int level);
	void draw(RenderWindow & window, float x, float y);
	vector<string> m_map;
private:
	void get_file();
	void read_level();
	void make_m_board();
	void push_objects();
	ifstream m_file;
	vector <vector <unique_ptr<StaticObject>>> m_board;
	Sprite m_sprite;
	int m_level;
};