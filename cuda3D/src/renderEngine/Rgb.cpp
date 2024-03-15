#include "../include/Rgb.h"

Rgb::Rgb()
{
	this->r = (unsigned char)0.0;
	this->g = (unsigned char)0.0;
	this->b = (unsigned char)0.0;
}

Rgb::Rgb(unsigned char r, unsigned char g, unsigned char b)
{
	this->r = r;
	this->g = g;
	this->b = b;
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