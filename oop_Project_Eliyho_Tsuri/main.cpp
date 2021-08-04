#ifdef _DEBUG
#pragma comment(lib, "sfml-main-d.lib")
#pragma comment(lib, "sfml-system-d.lib")
#pragma comment(lib, "sfml-window-d.lib")
#pragma comment(lib, "sfml-graphics-d.lib")
#pragma comment(lib, "sfml-audio-d.lib")
#elif defined(NDEBUG)
#pragma comment(lib, "sfml-main.lib")
#pragma comment(lib, "sfml-system.lib")
#pragma comment(lib, "sfml-window.lib")
#pragma comment(lib, "sfml-graphics.lib")
#pragma comment(lib, "sfml-audio.lib")
#else
#error "Unrecognized configuration!"
#endif
// --------------------- Include -----------------------
#include <iostream>
#include <algorithm>
#include <SFML/Graphics.hpp>
#include "Menu.h"
// ----------------------- Main ------------------------
int main()
{
	string m_run = "start";
	char run_game;
	cout << "How you run your program? (Debug ,Release)\n";
	while (true)
	{
		cout << "Please enter one of the options:\nD - for Debug\nR - for Release\n\n";
		cin >> m_run;
		transform(m_run.begin(), m_run.end(), m_run.begin(), ::tolower);
		if (m_run == "d" || m_run == "r")
			break;
	}
	run_game = m_run == "d" ? 'd' : 'r';
	try
	{
		Menu menu;
		menu.run(run_game);
	}
	catch (invalid_argument & argError)
	{
		cout << argError.what() << '\n';
	}
	return(EXIT_SUCCESS);
}