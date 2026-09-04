#include "Engine.h"
#include "SDL.h"

#pragma comment(lib,"SDL2")
#pragma comment(lib,"SDL2main")

#include <iostream>
#include <vector>
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

void DrawCircle(SDL_Renderer* render, SDL_Point point, int size)
{
	int CircleX, CircleY = 0;

	for (int i = 0; i < 360; i++)
	{
		CircleX = sin(i) * size + point.x;
		CircleY = cos(i) * size + point.y;
		SDL_SetRenderDrawColor(render, 255, 255, 255, 0);
		SDL_RenderDrawPoint(render, CircleX, CircleY);
	}
}
enum DrawMode
{
	Free,
	CirCle,
	Rect
};
int SDL_main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window* Window = SDL_CreateWindow("Game", 100, 100, 800, 600, SDL_WINDOW_SHOWN);

	SDL_Renderer* Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED);

	SDL_Event Event;

	//그림그리기 변수
	bool Pressed = false;
	int prev_mouse_x = 0;
	int prev_mouse_y = 0;

	//원형 찍기
	std::vector<SDL_Point> list;

	DrawMode Mode = DrawMode::Free;

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
			if (Event.key.keysym.sym == SDLK_1)
			{
				Mode = DrawMode::Free;
			}
			else if (Event.key.keysym.sym == SDLK_2)
			{
				Mode = DrawMode::CirCle;
			}
			else if (Event.key.keysym.sym == SDLK_3)
			{
				Mode = DrawMode::Rect;
			}
			
		}
		
		if (Event.type == SDL_MOUSEBUTTONUP)
		{
			switch (Mode)
			{
			case Free: {
				prev_mouse_x = 0;
				prev_mouse_y = 0;
				Pressed = false;
				break;
			}
			case CirCle:
				break;
			case Rect:
				break;
			default:
				break;
			}
		}
		else if (Event.type == SDL_MOUSEBUTTONDOWN)
		{
			switch (Mode)
			{
			case Free:
				Pressed = true;
				break;
			case CirCle:
			{
				SDL_Point point;
				point.x = 0;
				point.y = 0;
				SDL_GetMouseState(&point.x, &point.y);
				DrawCircle(Renderer, point, 40);
				list.push_back(point);
				break;
			}
			case Rect:
				break;
			default:
				break;
			}
			
		}
		else if (Event.type == SDL_MOUSEMOTION)
		{
			switch (Mode)
			{
			case Free:
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
				break;
			}
			case CirCle:
			{
				SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 0); // 흰색 배경
				SDL_RenderClear(Renderer);

				for (int i = 0; i < list.size(); i++)
				{
					DrawCircle(Renderer, list[i].x, list[i].y, 40);
				}
				SDL_Point point;
				point.x = 0;
				point.y = 0;
				SDL_GetMouseState(&point.x, &point.y);
				DrawCircle(Renderer, point.x, point.y, 40);
				break;
			}
			case Rect:
				break;
			default:
				break;
			}
			
			
		}


		SDL_RenderPresent(Renderer);
	}

	SDL_Quit();

	return 0;
}

