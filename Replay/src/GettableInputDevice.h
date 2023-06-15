#pragma once

#include <memory>
#include "lib/Keyboard.h"
#include "lib/Joypad.h"

class GettableInputDevice
{
public:
	GettableInputDevice() = default;
	virtual ~GettableInputDevice() = default;

	virtual KeyboardPtr	get_keyboard()	const = 0;
	virtual JoypadPtr	get_joypad()	const = 0;
};

