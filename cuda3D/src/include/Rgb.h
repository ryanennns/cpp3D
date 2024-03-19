#pragma once

class Rgb
{
private:
	unsigned char r;
	unsigned char g;
	unsigned char b;
public:
	Rgb();
	Rgb(unsigned char, unsigned char, unsigned char);
	unsigned char getRed();
	unsigned char getGreen();
	unsigned char getBlue();
	void setRed(unsigned char);
	void setGreen(unsigned char);
	void setBlue(unsigned char);
	Rgb operator*(double);
	Rgb operator*(Rgb);
	Rgb operator+(Rgb);
};