#pragma once
#include "SDL.h"

#pragma comment(lib,"SDL2")
#pragma comment(lib,"SDL2main")

class SDLDraw
{
public:
	SDLDraw();
	~SDLDraw();

	void DrawRect();
	void DrawFillRect();


protected:
	SDLDraw* Instance;

};

