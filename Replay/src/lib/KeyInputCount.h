#pragma once

#include "../VirtualController.h"
#include "../scenes/SceneContext.h"
#include "../scenes/keyconfig/KeyConfig.h"
#include <array>

class KeyInputCount
{
public:

	KeyInputCount() = default;
	~KeyInputCount() = default;

	static void init();
	static bool proc( VirtualController::key_type key );
	static unsigned Get( VirtualController::key_type key );
};
