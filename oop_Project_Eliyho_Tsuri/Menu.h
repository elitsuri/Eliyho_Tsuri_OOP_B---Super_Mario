#pragma once
#include "Button.h"

using namespace std;

class Menu
{
public:
	Menu();
	void run(const char m_run);
	~Menu() {};
private:
	vector <unique_ptr<Button>> m_vector_but;
	RenderWindow m_window;
	bool exit_on;
	Font m_font;
	Sprite m_back;
};