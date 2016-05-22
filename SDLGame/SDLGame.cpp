// main code for sdl 2d thing
// 2016 createjump

#include "stdafx.h"
#include "SDLGame.h"
#include "SDL.h"
#include "SDL_video.h"
#include "SDL_messagebox.h"
#include "SDL_error.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
SDL_Event event;

SDL_Window* Wnd = NULL;
SDL_Renderer* Rend = NULL;

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	
	
	

	Wnd = SDL_CreateWindow("SDL 2D Game Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
	if (Wnd == NULL) {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "SDL Error!","Window could not be created!",NULL);
	}
	Rend = SDL_CreateRenderer(Wnd,-1,SDL_RENDERER_ACCELERATED);
	if (Rend == NULL) {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "SDL Error!", "Renderer could not be created!", NULL);
	}
	
	
	SDL_Rect Rect = { SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 4, SCREEN_HEIGHT / 2};
	

	while (1) {
		
		SDL_Delay(200);
		SDL_SetRenderDrawColor(Rend, 50, 54, 100, SDL_ALPHA_OPAQUE);
		SDL_RenderFillRect(Rend,&Rect);
		SDL_RenderPresent(Rend);
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT)
			{
				SDL_DestroyRenderer(Rend);
				SDL_DestroyWindow(Wnd);
				SDL_Quit();

				return 0;
			}
		}
		} 
		// TODO: Add looping code here.
		
	}

	