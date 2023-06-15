#pragma once

#include "../VirtualController.h"

class SceneContext
{
public:

	SceneContext() = default;
	virtual ~SceneContext() = default;

	virtual VCtrlPtr get_input() const = 0;
};
