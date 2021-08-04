#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
using namespace sf;
class Resources
{
public:
	static Resources& get()
	{
		static Resources noun;
		return noun;
	};
	Texture *get_pic(int pic_num) { return &pic_arr[pic_num]; }
	Sprite get_sprite(int pic_num) { return pic_sprite[pic_num]; }
	Font get_font() { return m_font; }
	~Resources() {};
private:
	const int SIZE = 9;
	Resources()
	{
		pic_arr[0].loadFromFile("files/b.jpg");
		pic_arr[1].loadFromFile("files/menu_bottons.png");
		pic_arr[2].loadFromFile("files/Mario_Tileset.png");
		pic_arr[3].loadFromFile("files/coins.png");
		pic_arr[4].loadFromFile("files/back2.jpg");
		pic_arr[5].loadFromFile("files/StartBack.jpg");
		pic_arr[6].loadFromFile("files/win.png");
		pic_arr[7].loadFromFile("files/help.jpg");
		pic_arr[8].loadFromFile("files/gameover.jpg");
		m_font.loadFromFile("files/fonts/font.ttf");
		for (int i = 0; i < SIZE; ++i)
		{
			if (!&pic_arr[i])
			{
				throw (std::invalid_argument("No such files to build the game\n"));
				exit(1);
			}
		}
		if (!&m_font)
		{
			throw (std::invalid_argument("No such files to build the game\n"));
			exit(1);
		}
		for (int i = 0; i < SIZE; ++i)
		{
			pic_arr[i].setSmooth(true);
			pic_sprite[i].setTexture(pic_arr[i]);
		}
	};
	Resources(const Resources&) = delete;
	Resources &operator=(const Resources&) = delete;
	Texture pic_arr[9];
	Sprite pic_sprite[9];
	Font m_font;
};