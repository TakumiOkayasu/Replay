#pragma once

#include "Utility.h"

class Shape
{
public:
	Shape()  = default;
	virtual ~Shape() = default;

	virtual const Shape& setCoordinate( Utility::pos_t< int > const& pos ) = 0;
	virtual const Shape& Fill() = 0;
	virtual const Shape& Color() = 0;
};

