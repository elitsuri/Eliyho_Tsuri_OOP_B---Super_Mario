#include "Goomba.h"

Goomba::Goomba()
{
	m_rect = FloatRect(1.0f, 1.0f, 1.0f, 1.0f);
	m_pos.x = 0.05f;
	m_pos.y = 0.1f;
	m_frame = 0;
	m_life = true;
	m_power = 10;
	m_onGround = false;
}

void Goomba::set(int x, int y)
{
	m_rect = FloatRect(float(x), float(y), 16.f, 17.f);
	m_pos.x = 0.05f;
	m_pos.y = 0.1f;
	m_frame = 0;
	m_life = true;
	m_power = 10;
	m_onGround = true;
}

void Goomba::move(vector <string> &map, float time, float offsetX, float offsetY)
{
	m_rect.left += m_pos.x * time;
	Collision(0, map);
	if (m_pos.y > 0 || !m_onGround)
	{
		m_pos.y = m_pos.y + 0.0005f * time;
		m_rect.top += m_pos.y * time;
		m_onGround = false;
		Collision(1, map);
	}
	m_frame += time * 0.005f;
	if (m_frame > 2.f)
		m_frame -= 2.f;
	m_sprite.setTextureRect(IntRect(18 * int(m_frame), 0, 16, 16));
	if (!m_life)
		m_sprite.setTextureRect(IntRect(58, 0, 16, 16));
	m_sprite.setPosition(m_rect.left - offsetX, m_rect.top - offsetY + 757.1f);
	if (!m_life)
		m_power = 0;
}

void Goomba::Collision(int num, vector <string> &map)
{
	for (int i = (int)m_rect.top / 16; i < (m_rect.top + m_rect.height) / 16; i++)
	{
		for (int j = (int)m_rect.left / 16; j < (m_rect.left + m_rect.width) / 16; j++)
		{
			if ((map[i][j] == 'P') || (map[i][j] == 'k') ||
				(map[i][j] == '0') || (map[i][j] == 'r') ||
				(map[i][j] == 't') || (map[i][j] == 'c'))
			{
				if (m_pos.y > 0 && num == 1)
				{
					m_rect.top = i * 16.f - m_rect.height;
					m_pos.y = 0;
					m_onGround = true;
				}
				if (m_pos.y < 0 && num == 1)
				{
					m_rect.top = i * 16.f + 16.f;
					m_pos.y = 0;
				}
				if (m_pos.x > 0)
				{
					m_rect.left = j * 16.f - m_rect.width;
					m_pos.x *= -1;
				}
				else if (m_pos.x < 0)
				{
					m_rect.left = j * 16.f + 16.f;
					m_pos.x *= -1;
				}
			}
		}
	}
}

void Goomba::setPos(float val, Direction dirct, bool onGround)
{
	if (dirct == stop)
	{
		m_pos.x = val;
		m_direction = dirct;
	}
	else
		m_pos.y = val;
	m_onGround = onGround;
}
