//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include <vector>

#include "Sphere.h"
#include "Vector3D.h"
#include "ViewPort.h"
#include "Ray.h"
#include "Rgb.h"
#include "Triangle.h"
#include "Object.h"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

void set_pixel(SDL_Surface* surface, int x, int y, Uint32 color)
{
	if (x >= 0 && x < surface->w && y >= 0 && y < surface->h) {
		Uint32* pixels = (Uint32*)surface->pixels;
		pixels[(y * surface->w) + x] = color;
	}
}

int main(int argc, char* args[])
{
	//The window we'll be rendering to
	SDL_Window* window = NULL;

	//The surface contained by the window
	SDL_Surface* screenSurface = NULL;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		//Create window
		window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			//Get window surface
			screenSurface = SDL_GetWindowSurface(window);

			Uint32 staticColor = SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF);
			Object object = Object();
			object.addSurface(
				new Triangle(
					Vector3D(-1.5, 1, 3),
					Vector3D(1, -1.5, 3),
					Vector3D(1, 1, 3)
				)
			);
			object.addSurface(new Sphere(Vector3D(8, 8, 10), 1));

			ViewPort viewPort = ViewPort(SCREEN_WIDTH, SCREEN_HEIGHT);

			vector<vector<Ray>> rays = viewPort.getRays();

			for (int y = 0; y < SCREEN_HEIGHT; ++y)
			{
				for (int x = 0; x < SCREEN_WIDTH; ++x)
				{
					if (object.intersections(rays.at(y).at(x)).size() > 0)
					{
						set_pixel(screenSurface, x, y, staticColor);
					}
				}
			}

			//Update the surface
			SDL_UpdateWindowSurface(window);

			//Hack to get window to stay up
			SDL_Event e;
			bool quit = false;
			while (quit == false)
			{
				while (SDL_PollEvent(&e))
				{
					if (e.type == SDL_QUIT) {
						quit = true;
					}
				}
			}
		}
	}

	//Destroy window
	SDL_DestroyWindow(window);

	//Quit SDL subsystems
	SDL_Quit();

	return 0;
}
