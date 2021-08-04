#include "StartButton.h"

StartButton::StartButton()
{
	m_button_on = m_sprite;
	m_sprite.setTextureRect(IntRect(210, 150, 500, 70));
	m_button_on.setTextureRect(IntRect(210, 234, 500, 70));
	m_sprite.setPosition(700, 250);
	m_button_on.setPosition(700, 260);
	m_button_before = m_sprite;
}
void StartButton::ClickOn(Vector2f pos, RenderWindow &win, bool & flag, const char run_game)
{
	if (!m_sprite.getGlobalBounds().contains(pos))
		return;
	m_sound.play();
	win.close();
	game.run(run_game);
}

void StartButton::moveOn(Vector2f pos)
{
	if (m_sprite.getGlobalBounds().contains(pos))
		m_sprite = m_button_on;
	else
		m_sprite = m_button_before;
}