#include "Mario.h"

Mario::Mario()
{
	m_rect = FloatRect(100, 180, 16, 17);
	m_pos.x = 0.1f;
	m_pos.y = 0.1f;
	m_frame = 0;
	m_power = 20;
	m_life = true;
	m_onGround = false;
	m_coin.openFromFile("files/sound/coin.ogg");
	if (!&m_coin)
		throw(invalid_argument("No such files to build the game\n"));
}

void Mario::move(vector <string> &map, float time, float offsetX, float offsetY)
{
	m_rect.left += m_pos.x * time;
	Collision(0, map);
	if (!m_onGround)
		m_pos.y = m_pos.y + 0.0005f * time + (float)0.003;
	m_rect.top += m_pos.y * time;
	m_onGround = false;
	Collision(1, map);
	m_frame += time * 0.005f;
	if (m_frame > 3)
		m_frame -= 3;
	if (m_pos.x > 0)
		m_sprite.setTextureRect(IntRect(109 + 31 * int(m_frame), 144, 14, 19));
	if (m_pos.x < 0)
		m_sprite.setTextureRect(IntRect(109 + 31 * int(m_frame) + 16, 144, -18, 18));
	m_sprite.setPosition(m_rect.left - offsetX, m_rect.top - offsetY + 754);
	if (m_power >= 20 && m_life)
		m_power = 20;
	if (!m_life)
		m_power = 0;
	m_pos.x = 0;
}

void Mario::Collision(int num, vector <string> &map)
{
	point = 0;
	for (int i = (int) m_rect.top / 16; i < (m_rect.top + m_rect.height) / 16; i++)
	{
		for (int j = (int) m_rect.left / 16; j < (m_rect.left + m_rect.width) / 16; j++)
		{
			if ((map[i][j] == 'k') || (map[i][j] == 'M') ||
				(map[i][j] == '0') || (map[i][j] == 'r') ||
				(map[i][j] == 't') || (map[i][j] == 'c'))
			{
				if (map[i][j] == 'M')
					m_win = true;
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
					if (map[i][j] == 'k' || map[i][j] == 'c')
					{
						if (map[i][j] == 'c')
						{
							m_coin.play();
							point++;
						}
						map[i][j] = ' ';
					}
				}
				if (m_pos.x > 0 && num == 0)
					m_rect.left = j * 16.f - m_rect.width;
				if (m_pos.x < 0 && num == 0)
					m_rect.left = j * 16.f + 16.f;
			}
		}
	}
}

void Mario::setPos(float val, Direction dir, bool onGround)
{
	if (dir == go_left || dir == go_right)
	{
		m_pos.x = val;
		m_direction = dir;
	}
	else
		m_pos.y = val;
}