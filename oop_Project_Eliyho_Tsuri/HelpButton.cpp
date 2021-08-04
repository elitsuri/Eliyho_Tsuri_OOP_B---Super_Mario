#include "HelpButton.h"

HelpButton::HelpButton()
{
	m_button_on = m_sprite;
	m_sprite.setTextureRect(IntRect (333,330, 420, 70));
	m_button_on.setTextureRect(IntRect(322, 409, 420, 70));
	m_sprite.setPosition(820,450);
	m_button_on.setPosition(820,460);
	m_button_before = m_sprite;
	m_button_help = false;
}

void HelpButton::ClickOn(Vector2f pos, RenderWindow &win, bool & flag, const char run)
{
	if (!m_sprite.getGlobalBounds().contains(pos))
		return;	
	m_sound.play();
	win.clear();
	win.draw(Resources::get().get_sprite(7));
	win.display();

	while (win.isOpen())
	{
		Event event;
		while (win.pollEvent(event))
		{
			switch (event.type)
			{
				case Event::MouseButtonPressed:
				{
					m_sound.play();
					win.close();
				}
			}
		}
	}
}

void HelpButton::moveOn(Vector2f pos)
{
	if (m_sprite.getGlobalBounds().contains(pos))
		m_sprite = m_button_on;
	else
		m_sprite = m_button_before;
}