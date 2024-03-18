#include <vector>
#include <algorithm>
#include "../include/ViewDriver.h"
#include "../include/Sphere.h"
#include "../include/Light.h"

ViewDriver::ViewDriver(Scene* scene, ViewPort viewPort)
{
	this->scene = scene;
	this->viewPort = viewPort;
}

vector<vector<Rgb>> ViewDriver::processFrame()
{
	vector<vector<Rgb>> rgbValues;
	vector<vector<Ray>> rays = viewPort.getRays();

	for (int y = 0; y < rays.size(); y++)
	{
		vector<Ray> row = rays.at(y);
		vector<Rgb> rgbColumn;
		for (int x = 0; x < row.size(); x++)
		{
			Ray ray = row.at(x);
			vector<HitDetection> intersections = scene->intersections(ray);
			if (intersections.size() > 0)
			{
				rgbColumn.push_back(processLighting(intersections.at(0)));
			}
			else
			{
				rgbColumn.push_back(Rgb(0, 0, 0));
			}
		}
		rgbValues.push_back(rgbColumn);
	}

	return rgbValues;
}

Rgb ViewDriver::processLighting(HitDetection intersection)
{
    Light* light = this->scene->getLights().at(0); // Assuming you're only considering one light for simplicity

    double lightDistance = intersection.getHitPoint().distanceBetween(light->getOrigin());
    double effectiveIntensity = light->getIntensity() - lightDistance;

    // Defining the dark gray as an example, adjust as needed
    Rgb darkGray(16, 16, 16); // Dark gray, adjust values as you see fit
    Rgb white(255, 255, 255); // White

    // Retrieve original color
    double r = intersection.getColour().getRed();
    double g = intersection.getColour().getGreen();
    double b = intersection.getColour().getBlue();

    if (effectiveIntensity >= light->getIntensity()) {
        // Light is strong enough to make the object appear white
        return white;
    }
    
    if (effectiveIntensity <= 0) {
        // Light is too weak, return dark gray
        return darkGray;
    }

    // Scale color based on effectiveIntensity
    double scaleFactor = effectiveIntensity / light->getIntensity();
    r = darkGray.getRed() + (r - darkGray.getRed()) * scaleFactor;
    g = darkGray.getGreen() + (g - darkGray.getGreen()) * scaleFactor;
    b = darkGray.getBlue() + (b - darkGray.getBlue()) * scaleFactor;

    // Clamp RGB values to ensure they are within the valid range [0, 255]
    r = std::min(std::max(r, 0.0), 255.0);
    g = std::min(std::max(g, 0.0), 255.0);
    b = std::min(std::max(b, 0.0), 255.0);

    return Rgb(r, g, b);
}
