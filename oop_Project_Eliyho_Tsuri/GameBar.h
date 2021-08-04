#pragma once
#include "Resources.h"
using namespace sf;
using namespace std;

class GameBar
{
public:
	GameBar(int level, int lives, int points);
	void draw(RenderWindow & window);
	~GameBar() {};
private:
	void set_font_text();
	void set_color_size();
	void set_position();	
	Text m_level_text;
	Text m_points_text;
	Text m_lives_text;
	Text m_num_level;
	Text m_num_points;
	Text m_num_lives;
	Font m_font;
	int m_level;
	int m_lives;
	int m_points;
};