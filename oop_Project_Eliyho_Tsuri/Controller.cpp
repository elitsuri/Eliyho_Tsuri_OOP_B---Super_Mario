#include "Controller.h"
#include <iostream>

Controller::Controller()
{
	load_musics();
	allocEnemies();
	initializeEnemies();
}
void Controller::load_musics()
{
	m_backs.push_back(Resources::get().get_sprite(0));
	m_backs.push_back(Resources::get().get_sprite(4));
	m_backs.push_back(Resources::get().get_sprite(6));
	m_backs.push_back(Resources::get().get_sprite(8));
	m_back_music[0].openFromFile("files/sound/back1.ogg");
	m_back_music[1].openFromFile("files/sound/back2.ogg");
	m_back_music[2].openFromFile("files/sound/back3.ogg");
	m_game_music[0].openFromFile("files/sound/death.ogg");
	m_game_music[1].openFromFile("files/sound/jump.ogg");
	m_game_music[2].openFromFile("files/sound/kick.ogg");
	m_game_music[3].openFromFile("files/sound/powerup.ogg");
	m_game_music[4].openFromFile("files/sound/winner.ogg");
	m_game_music[5].openFromFile("files/sound/wall.ogg");
	m_game_music[6].openFromFile("files/sound/GameOver.ogg");
	for (unsigned i = 0; i < 3; ++i)
	{
		if (!&m_game_music[i])
		{
			throw (invalid_argument("No such files to build the game\n"));
			exit(EXIT_FAILURE);
		}
		m_back_music[i].setLoop(true);
		m_back_music[i].setVolume(10);
	}
	for (unsigned i = 0; i < 7; ++i)
	{
		if (!&m_game_music[i])
		{
			throw (invalid_argument("No such files to build the game\n"));
			exit(EXIT_FAILURE);
		}
		m_game_music[i].setVolume(70);
	}
}

void Controller::allocEnemies()
{
	for (unsigned i = 0; i < SIZE; ++i)
	{
		m_enemies.push_back(make_shared<Goomba>());
		m_enemies.push_back(make_shared<Turtle>());
	}
}

void Controller::initializeEnemies()
{
	unsigned index = 0;
	for (auto &enemy : m_enemies)
	{
		if (index == 0)
			enemy->set(220 * index + 200, 13 * 23);
		else if (index % 2 == 0)
			enemy->set(220 * index + 100, 13 * 23);
		else
			enemy->set(220 * index + 100, 13 * 23);
		index++;
	}
}

void Controller::initializeView()
{
	View view = m_window.getDefaultView();
	view.zoom(0.47f);
	view.setCenter({ 474, 811 });
	m_window.setView(view);
}

void Controller::run(const char m_run)
{
	float time;
	float m_speed = m_run == 'd' ? 1.6f : 3.2f;
	float m_jump = m_run == 'd' ?  -0.30f : -0.52f;
	
	m_window.create(VideoMode::getFullscreenModes()[0], "Super-Mario", Style::Fullscreen);
	for (num_level = 1; num_level < 4 && !m_end ;)
	{
		initializeView();
		m_win = false;
		my_level = make_unique<Level>(num_level);
		m_back_music[num_level - 1].play();
		m_mario = make_unique<Mario>();
		while (m_window.isOpen())
		{
			clock.restart();
			GameBar bar(num_level, m_lives, m_points);
			time = (float)clock.getElapsedTime().asMicroseconds();
			time = time / m_speed;
			while (m_window.pollEvent(event))
			{
				if (event.key.code == Keyboard::Escape)
				{
					m_window.close();
					m_end = true;
				}
			}
			if (m_end)
				continue;
			if (Keyboard::isKeyPressed(Keyboard::Q))
				switch_sound();
			if (Keyboard::isKeyPressed(Keyboard::Left))
				m_mario->setPos(-0.1f, go_left, true);
			if (Keyboard::isKeyPressed(Keyboard::Right))
				m_mario->setPos(0.1f, go_right, true);
			if (Keyboard::isKeyPressed(Keyboard::Up))
			{
				if (m_mario->getGround())
				{
					m_game_music[1].play();
					m_mario->setPos(m_jump, go_up, true);
				}
			}			
			move_objects(my_level, time);
			draw(my_level, bar);
			m_window.display();
			if (!m_mario->getLife() || m_lives == 0)
			{
				game_over();
				break;
			}
			if (m_win)
			{
				winner_over();
				break;
			}
		}
	}
}

void Controller::move_objects(unique_ptr<Level> &my_level, float time)
{
	m_mario->move(my_level->m_map, time, offsetX, offsetY);
	for (auto &enemy : m_enemies)
		enemy->move(my_level->m_map, time, offsetX, offsetY);
	if (m_mario->point > 0)
		m_points++;
	for (auto &enemy : m_enemies)
	{
		if (m_mario->getRect().intersects(enemy->getRect()))
		{
			if (enemy->getLife())
			{
				if (m_mario->getPos().y > 0)
				{
					enemy->setPos(0, stop, false);
					m_mario->setPos(-0.19f, stop, true);
					enemy->setLife(false);
					m_game_music[2].play();
					m_points += 2;
				}
				else
					m_mario->setLife(false);
			}
		}
	}
	if (m_points >= 20)
		m_win = true;
	if (m_mario->getRect().left > 200)
		offsetX = m_mario->getRect().left - 200;
}

void Controller::switch_sound()
{
	if (m_sound_switch)
	{
		m_back_music[num_level - 1].setVolume(0);
		for (unsigned i = 0; i < 7; ++i)
			m_game_music[i].setVolume(0);
		m_sound_switch = false;
	}
	else
	{
		m_back_music[num_level - 1].setVolume(40);
		for (unsigned i = 0; i < 7; ++i)
			m_game_music[i].setVolume(70);
		m_sound_switch = true;
	}
}

void Controller::winner_over()
{
	Sleep(50);
	m_back_music[num_level - 1].stop();
	m_game_music[4].play();
	m_window.clear();
	m_window.draw(m_backs[2]);
	m_window.display();
	m_points = 0;
	num_level++;
	m_mario = make_unique<Mario>();
	initializeEnemies();
	Sleep(7500);
	if (num_level > 3)
		m_end = true;
}

void Controller::game_over()
{
	m_back_music[num_level - 1].stop();
	m_game_music[0].play();
	m_window.clear();
	m_window.draw(m_backs[3]);
	m_window.display();
	Sleep(3300);
	m_lives--;
	if (m_lives == 0)
		m_end = true;
	else
	{
		initializeEnemies();
		m_back_music[num_level - 1].play();
	}
}

void Controller::draw(unique_ptr<Level> &my_level, GameBar & bar)
{
	m_window.draw(m_backs[num_level - 1]);
	bar.draw(m_window);
	my_level->draw(m_window, offsetX, offsetY);
	for (auto &enemy : m_enemies)
		enemy->draw(m_window);
	m_mario->draw(m_window);
}
