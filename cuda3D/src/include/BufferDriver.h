#pragma once

#include <vector>
#include "Ray.h"

class BufferDriver
{
public:
	virtual unsigned char* generateBuffer(std::vector<std::vector<Ray>>) = 0;
private:
};