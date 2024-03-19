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
#include "Scene.h"
#include "ViewDriver.h"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 800;

void set_pixel(SDL_Surface* surface, int x, int y, Rgb& color)
{
	if (x >= 0 && x < surface->w && y >= 0 && y < surface->h) {
		Uint32* pixels = (Uint32*)surface->pixels;
		Uint32 pixelColor = SDL_MapRGB(
			surface->format,
			color.getRed(),
			color.getGreen(),
			color.getBlue()
		);

		pixels[(y * surface->w) + x] = pixelColor;
	}
}

int main(int argc, char* args[])
{
	SDL_Window* window = NULL;

	SDL_Surface* screenSurface = NULL;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			screenSurface = SDL_GetWindowSurface(window);

			Uint32 staticColor = SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF);
			Scene* scene = new Scene();

			Object* object = new Object();	
			object->addSurface(new Sphere(Vector3D(-0.5, -0.5, 1.5), 0.1));
			object->setColour(Rgb(251, 182, 209));
			scene->addObject(object);

			Object* object1 = new Object();
			object1->addSurface(new Sphere(Vector3D(-1, -1, 2), 0.4));
			object1->setColour(Rgb(253, 253, 150));
			scene->addObject(object1);

			Object* object2 = new Object();
			object2->addSurface(new Sphere(Vector3D(-1, 1, 2), 0.8));
			object2->setColour(Rgb(150, 150, 253));
			scene->addObject(object2);

			Object* sphere = new Object();
			sphere->addSurface(new Sphere(Vector3D(1, 0, 2), 0.3));
			sphere->setColour(Rgb(133, 209, 93));
			scene->addObject(sphere);

			//Object* triangle = new Object();
			//triangle->addSurface(new Triangle(
			//	Vector3D(1, 1, 4),
			//	Vector3D(-1, 1, 5),
			//	Vector3D(-1, -1, 4)
			//));
			//triangle->addSurface(new Triangle(
			//	Vector3D(1, 1, 4),
			//	Vector3D(-1, -1, 4),
			//	Vector3D(1, -1, 5)
			//));
			//scene->addObject(triangle);

			scene->addLight(new Light(Vector3D(0, 0, 1)));

			ViewPort viewPort = ViewPort(SCREEN_WIDTH, SCREEN_HEIGHT);

			ViewDriver viewDriver = ViewDriver(scene, viewPort);
			vector<vector<Rgb>> rgbValues = viewDriver.processFrame();

			for (int y = 0; y < SCREEN_HEIGHT; ++y)
			{
				for (int x = 0; x < SCREEN_WIDTH; ++x)
				{
					set_pixel(screenSurface, x, y, rgbValues.at(y).at(x));
				}
			}

			SDL_UpdateWindowSurface(window);

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

	SDL_DestroyWindow(window);

	SDL_Quit();

	return 0;
}
