#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
//#include <Windows.h>
#include "Resources.h"
#include "GameBar.h"
#include "Colission.h"
#include "Level.h"
#include "DynamicObject.h"

class Controller
{
public:
	Controller();
	void run(const char m_run);
	~Controller() {};
private:
	void load_musics();
	void allocEnemies();
	void initializeEnemies();
	void initializeView();
	void draw(unique_ptr<Level> &m_map, GameBar & bar);
	void move_objects(unique_ptr<Level> &m_map, float time);
	void switch_sound();
	void winner_over();
	void game_over();
	unique_ptr<Level> my_level;
	unique_ptr<Mario> m_mario;
	vector<Sprite> m_backs;
	vector<shared_ptr<Enemy>> m_enemies;
	RenderWindow m_window;
	Music m_back_music[3];
	Music m_game_music[7];
	Clock clock;
	Event event;
	bool m_sound_switch = true;
	unsigned SIZE = 17;
	bool m_win = false;
	int num_level;
	bool m_end = false;
	int m_points = 0;
	int m_lives = 3;
	float offsetX = 0;
	float offsetY = 50;
};
