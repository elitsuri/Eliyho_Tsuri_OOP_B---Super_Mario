#include "GameBar.h"
const int SIZE = 38;
const float Y = 553;


GameBar::GameBar(int level, int lives, int points)
	:m_level(level),m_lives(lives),m_points(points),m_font(Resources::get().get_font())
{
	set_font_text();
	set_color_size();
	set_position();
}

void GameBar::set_font_text()
{
	m_level_text.setFont(m_font);
	m_num_lives.setFont(m_font);
	m_num_level.setFont(m_font);
	m_points_text.setFont(m_font);
	m_num_points.setFont(m_font);
	m_lives_text.setFont(m_font);
	m_lives_text.setString("LIVE:");
	m_level_text.setString("LEVEL:");
	m_points_text.setString("SCORE:");
	m_num_lives.setString(to_string(m_lives));
	m_num_level.setString(to_string(m_level));
	m_num_points.setString(to_string(m_points));
}

void GameBar::set_color_size()
{
	Color m_color = Color::Blue;
	if (m_level == 2)
		m_color = Color::White;
	m_num_points.setFillColor(m_color);
	m_num_lives.setFillColor(m_color);
	m_points_text.setFillColor(m_color);
	m_level_text.setFillColor(m_color);
	m_num_level.setFillColor(m_color);
	m_lives_text.setFillColor(m_color);
	m_num_lives.setCharacterSize(SIZE);
	m_level_text.setCharacterSize(SIZE);
	m_points_text.setCharacterSize(SIZE);
	m_num_level.setCharacterSize(SIZE);
	m_lives_text.setCharacterSize(SIZE);
	m_num_points.setCharacterSize(SIZE);
}

void GameBar::set_position()
{
	m_lives_text.setPosition(35, Y);
	m_num_lives.setPosition(148, Y);

	m_points_text.setPosition(373, Y);
	m_num_points.setPosition(521, Y);

	m_level_text.setPosition(750, Y);
	m_num_level.setPosition(898, Y);
}
void GameBar::draw(RenderWindow & window)
{
	window.draw(m_lives_text);
	window.draw(m_num_lives);
	window.draw(m_level_text);
	window.draw(m_num_level);
	window.draw(m_points_text);
	window.draw(m_num_points);
}