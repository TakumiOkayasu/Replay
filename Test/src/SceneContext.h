#pragma once

#include "../Replay/Replay/src/VirtualController.h"
#include "SceneChangeListener.h"

class SceneContext
{
public:

	SceneContext() = default;
	virtual ~SceneContext() = default;

	virtual VCtrlPtr get_input() const = 0;
};


