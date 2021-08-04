#include "ExitButton.h"

ExitButton::ExitButton()
{
	m_button_on = m_sprite;
	m_sprite.setTextureRect(IntRect(317, 507, 250, 75));
	m_button_on.setTextureRect(IntRect(322, 585, 250, 75));
	m_sprite.setPosition(820, 650);
	m_button_on.setPosition(830, 660);
	m_button_before = m_sprite;
}
void ExitButton::ClickOn(Vector2f pos, RenderWindow &win, bool & flag, const char run)
{
	if (!m_sprite.getGlobalBounds().contains(pos))
		return;
	m_sound.play();
	flag = false;
	win.close();
}

void ExitButton::moveOn(Vector2f pos)
{
	if (m_sprite.getGlobalBounds().contains(pos))
		m_sprite = m_button_on; 
	else
		m_sprite = m_button_before;
}