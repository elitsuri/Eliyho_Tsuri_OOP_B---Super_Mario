#include "Level.h"
#include "Wall.h"
#include "Brick.h"
#include "Cloud.h"
#include "Pipe.h"
#include "Bush.h"
#include "Hill.h"
#include "Box.h"
#include "Castle.h"

Level::Level(int level)
	:m_level(level), m_sprite(Resources::get().get_sprite(2))
{
	get_file();
	read_level();
	make_m_board();
	push_objects();
}

void Level::get_file()
{
	char num = (char) (m_level) +'0';
	string end = ".txt";
	string file_name = "";
	file_name += num;
	file_name += end;
	m_file.open(file_name);
	if (!m_file)
		throw (invalid_argument("No such files to build the game\n"));
}

void Level::read_level()
{
	string line;
	while (!m_file.eof())
	{
		getline(m_file, line);
		m_map.push_back(line);
	}
}

void Level::make_m_board()
{
	m_board.resize(H);
	for (int i = 0; i < H; i++)
		m_board[i].resize(W);

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
			m_board[i][j] = nullptr;
	}
}

void Level::push_objects()
{
	Vector2f pos;
	char icon;
	for (int y = 0; y < H; y++)
	{
		for (int x = 0; x < W; x++)
		{
			pos.x = (float) x * 16;
			pos.y = (float) 16 + 763;
			icon = m_map[y][x];
			switch (icon)
			{
			case 'r':m_board[y][x] = make_unique <Wall>(pos);
				break;
			case 'k':m_board[y][x] = make_unique <Brick>(pos);
				break;
			case 'w':m_board[y][x] = make_unique <Cloud>(pos);
				break;
			case 'c':m_board[y][x] = make_unique <Box>(pos);
				break;
			case 't':m_board[y][x] = make_unique <Pipe>(pos);
				break;
			case 's':m_board[y][x] = make_unique <Hill>(pos);
				break;
			case 'M':m_board[y][x] = make_unique <Castle>(pos);
				break;
			case 'l':m_board[y][x] = make_unique <Bush>(pos);
				break;
			}
		}
	}
}

void Level::draw(RenderWindow & window, float x, float y)
{
	Vector2f pos;
	int i = 0;
	static bool flag = false;
	for (auto &row : m_map)
	{
		int j = 0;
		for (auto &col : row)
		{
			if (flag)
				j++;
			m_sprite.setScale(1.0f, 1.0f);
			pos = { j * 16 - x, i * 16 - y + 763 };
			if (m_map[i][j] == 'k')	// brick
				m_sprite.setTextureRect(IntRect(143, 112, 16, 16));
			if (m_map[i][j] == 'w') // cloud
				m_sprite.setTextureRect(IntRect(96, 224, 48, 32));
			if (m_map[i][j] == 'c') // box
			{
				m_sprite.setTextureRect(IntRect(127, 113, 16, 16));
				pos.y++;
				if (m_level == 2)
					pos.x++;
			}
			if (m_map[i][j] == 't') // pipe
				m_sprite.setTextureRect(IntRect(2, 85, 32, 50));
			if (m_map[i][j] == 'r') // wall
			{
				m_sprite.setTextureRect(IntRect(111, 112, 16, 17));
				pos.y += 2;
			}
			if (m_map[i][j] == 's') // hill
			{
				m_sprite.setTextureRect(IntRect(0, 140, 48, 40));
				pos = { j * 16 - x, i * 16 - y + 760 };
			}
			if (m_map[i][j] == 'M') // castle
			{
				m_sprite.setTextureRect(IntRect(196, 2, 106, 111));
				m_sprite.setScale(1.7f, 1.7f);
				pos = { j * 16 - x, i * 16 - y + 592 };

			}
			if (m_map[i][j] == 'l') // bush
			{
				m_sprite.setTextureRect(IntRect(161, 118, 70, 23));
				pos = { j * 16 - x, i * 16 - y + 757 };
			}
			m_sprite.setPosition(pos);
			flag = true;
			if (m_map[i][j] == ' ' || m_map[i][j] == '0')
				continue;
			window.draw(m_sprite);
		}
		i++;
	}
}

/*
void Level::draw(RenderWindow & window, float clock)
{
for (int y = 0; y < H; y++)
{
for (int x = 0; x < W; x++)
{
if (m_board[y][x])
m_board[y][x]->draw(window);
}
}

}
*/
