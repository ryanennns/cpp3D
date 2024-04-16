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

const int SCREEN_WIDTH = 250;
const int SCREEN_HEIGHT = 250;

void cleanup(SDL_Window* window)
{
	SDL_DestroyWindow(window);

	SDL_Quit();
}

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
		cleanup(window);

		return -1;
	}

	window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == NULL)
	{
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		cleanup(window);

		return -2;
	}

	screenSurface = SDL_GetWindowSurface(window);

	for(double i = 0.0; i >= 0.0; i += 0.1)
	{
		Scene* scene = new Scene();

		printf("%lf", i);
		// =============================================================
		// SPHERE OVER RAMP
		// =============================================================
		Object* triangle = new Object();
		triangle->addSurface(new Triangle(
			Vector3D(2, 2, 3),
			Vector3D(-2, 2, 3),
			Vector3D(-2, 0, 4),
			Rgb(255, 100, 0),
			1.01
		));
		triangle->addSurface(new Triangle(
			Vector3D(2, 2, 3),
			Vector3D(-2, 0, 4),
			Vector3D(2, 0, 4),
			Rgb(0, 255, 100),
			1.01
		));
		triangle->addSurface(new Triangle(
			Vector3D(2, -1, 6),
			Vector3D(-2, 0, 4),
			Vector3D(2, 0, 4),
			Rgb(0, 100, 255),
			1.01
		));
		triangle->addSurface(new Triangle(
			Vector3D(2, -1, 6),
			Vector3D(-2, 0, 4),
			Vector3D(-2, -1, 6),
			Rgb(255, 0, 255),
			1.01
		));
		Object* sphere = new Object();
		sphere->addSurface(new Sphere(
			Vector3D(-1 + i, -1, 3.75),
			0.5,
			Rgb(100, 200, 255),
			16
		));
		sphere->setColour(Rgb(209, 133, 93));
		scene->addObject(sphere);
		scene->addObject(triangle);

		scene->addLight(new Light(Vector3D(0, -2, 3)));

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
		delete scene;
	}

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

	return 0;
}

// =============================================================
// CUBE OFFSET
// =============================================================
//Object* triangle = new Object();
//// First triangle
//triangle->addSurface(new Triangle(
//	Vector3D(-1, 2, 5), // Moved by -1 in X
//	Vector3D(-3, 2, 5), // Moved by -1 in X
//	Vector3D(-3, 0, 4), // Moved by -1 in X
//	Rgb(255, 100, 0),
//	2
//));

//// Second triangle
//triangle->addSurface(new Triangle(
//	Vector3D(-1, 2, 5), // Moved by -1 in X
//	Vector3D(-3, 0, 4), // Moved by -1 in X
//	Vector3D(-1, 0, 4), // Moved by -1 in X
//	Rgb(0, 0, 100),
//	2
//));

//// Third triangle
//triangle->addSurface(new Triangle(
//	Vector3D(-1, -1, 6), // Moved by -1 in X
//	Vector3D(-3, 0, 4), // Moved by -1 in X
//	Vector3D(-1, 0, 4), // Moved by -1 in X
//	Rgb(0, 0, 255),
//	2
//));

//// Fourth triangle
//triangle->addSurface(new Triangle(
//	Vector3D(-1, -1, 6), // Moved by -1 in X
//	Vector3D(-3, 0, 4), // Moved by -1 in X
//	Vector3D(-3, -1, 6), // Moved by -1 in X
//	Rgb(255, 0, 255),
//	2
//));

//// Fifth triangle
//triangle->addSurface(new Triangle(
//	Vector3D(-1, 2, 5), // Moved by -1 in X
//	Vector3D(-1, 0, 4), // Moved by -1 in X
//	Vector3D(-1, -1, 6), // Moved by -1 in X
//	Rgb(255, 0, 0),
//	2
//));

//triangle->addSurface(new Triangle(
//	Vector3D(-1, 2, 5), // Moved by -1 in X
//	Vector3D(-1, 1, 7), // Moved by -1 in X
//	Vector3D(-1, -1, 6), // Moved by -1 in X
//	Rgb(255, 0, 255),
//	2
//));
//scene->addObject(triangle);
//scene->addObject(sphere);


//scene->addLight(new Light(Vector3D(-2, 0.5, 2)));
