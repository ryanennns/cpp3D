#include "../include/Rgb.h"

Rgb::Rgb()
{
	this->r = 0.0;
	this->g = 0.0;
	this->b = 0.0;
}

unsigned char Rgb::getRed()
{
	return this->r;
}

unsigned char Rgb::getGreen()
{
	return this->g;
};

unsigned char Rgb::getBlue()
{
	return this->b;
}

void Rgb::setRed(unsigned char value)
{
	this->r = value;
}

void Rgb::setGreen(unsigned char value)
{
	this->g = value;
};

void Rgb::setBlue(unsigned char value)
{
	this->b = value;
}