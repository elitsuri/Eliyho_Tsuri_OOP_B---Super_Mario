#include "Menu.h"
#include "StartButton.h"
#include "HelpButton.h"
#include "ExitButton.h"

Menu::Menu()
{
	m_vector_but.push_back(make_unique<StartButton>());
	m_vector_but.push_back(make_unique<HelpButton>());
	m_vector_but.push_back(make_unique<ExitButton>());
	m_back = Resources::get().get_sprite(5);
}

void Menu::run(const char m_run)
{
	m_window.create(VideoMode::getFullscreenModes()[0], "Super-Mario", Style::Fullscreen);
	while (m_window.isOpen())
	{
		Event event;
		Vector2f mouseCoords;
		while (m_window.pollEvent(event))
		{
			switch (event.type)
			{
				case Event::Closed:
				{
					exit_on = false;
					m_window.close();
					break;
				}
				case Event::MouseButtonPressed:
				{
					mouseCoords.x = (float)event.mouseButton.x;
					mouseCoords.y = (float)event.mouseButton.y;
					for (size_t i = 0; i < m_vector_but.size(); ++i)
						m_vector_but[i]->ClickOn(mouseCoords, m_window, exit_on, m_run);
					break;
				}
				case Event::MouseMoved:
				{
					mouseCoords = m_window.mapPixelToCoords({ event.mouseMove.x,event.mouseMove.y });
					for (size_t i = 0; i < m_vector_but.size(); ++i)
						m_vector_but[i]->moveOn(mouseCoords);
					break;
				}
			}
		}
		m_window.clear();
		m_window.draw(m_back);
		for (size_t i = 0; i < m_vector_but.size(); ++i)
			m_vector_but[i]->draw(m_window);
		m_window.display();
		if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
		{
			exit_on = false;
			m_window.close();
			break;
		}
	}
}

