#pragma once
#include "lib/Utility.h"

class Mover
{
public:
	Mover() = default;
	virtual ~Mover() = default;

	virtual void move() = 0;
};