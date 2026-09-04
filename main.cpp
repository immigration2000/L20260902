#include "Engine.h"
#include "SDL.h"

#pragma comment(lib,"SDL2")
#pragma comment(lib,"SDL2main")

#include <iostream>
//int main()
//{
//	GEngine->Init();
//
//	GEngine->Run();
//
//	GEngine->Exit();
//
//	return 0;
//}

void DrawCircle(SDL_Renderer* render, int x, int y, int size)
{
	int CircleX, CircleY = 0;

	for (int i = 0; i < 360; i++)
	{
		CircleX = sin(i) * size + x;
		CircleY = cos(i) * size + y;
		SDL_SetRenderDrawColor(render, 255, 255, 255, 0);
		SDL_RenderDrawPoint(render, CircleX, CircleY);
	}
}

int SDL_main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window* Window = SDL_CreateWindow("Game", 100, 100, 800, 600, SDL_WINDOW_SHOWN);

	SDL_Renderer* Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED);

	SDL_Event Event;

	//그림그리기 변수
	/*bool Pressed = false;
	int prev_mouse_x = 0;
	int prev_mouse_y = 0;*/

	//원형 찍기
	
	while (1)
	{
		SDL_PollEvent(&Event);
		if (Event.type == SDL_QUIT)
		{
			break;
		}
		else if (Event.type == SDL_KEYDOWN)
		{
			if (Event.key.keysym.sym == SDLK_ESCAPE)
			{
				break;
			}
			
		}
		//마우스 기본 셋팅
		/*if (Event.type == SDL_MOUSEBUTTONUP)
		{

		}
		else if (Event.type == SDL_MOUSEBUTTONDOWN)
		{
		}
		else if (Event.type == SDL_MOUSEMOTION && Pressed)
		{
		}*/
		//그림 그리기
		/*if (Event.type == SDL_MOUSEBUTTONUP)
		{
			std::cout << "SDL_BUTTON_LEFT" << std::endl;
			prev_mouse_x = 0;
			prev_mouse_y = 0;
			Pressed = false;
		}
		else if (Event.type == SDL_MOUSEBUTTONDOWN)
		{
			std::cout << "SDL_MOUSEBUTTONDOWN" << std::endl;
			Pressed = true;
			
		}
		else if (Event.type == SDL_MOUSEMOTION && Pressed)
		{
			int X, Y = 0;
			SDL_GetMouseState(&X, &Y);
			if (prev_mouse_x != 0 && prev_mouse_y != 0)
			{
				SDL_SetRenderDrawColor(Renderer, 255, 255, 255, 0);
				SDL_RenderDrawLine(Renderer, prev_mouse_x, prev_mouse_y, X, Y);
			}
			
			std::cout << "Drawing" << std::endl;
			
			prev_mouse_x = X;
			prev_mouse_y = Y;
		}*/
		if (Event.type == SDL_MOUSEBUTTONUP)
		{

		}
		else if (Event.type == SDL_MOUSEBUTTONDOWN)
		{
			int X, Y = 0;
			SDL_GetMouseState(&X, &Y);
			std::cout << X << Y << std::endl;
			DrawCircle(Renderer,X,Y,40);
		}
		else if (Event.type == SDL_MOUSEMOTION)
		{
			
			
		}


		SDL_RenderPresent(Renderer);
	}

	SDL_Quit();

	return 0;
}

