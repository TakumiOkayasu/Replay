#pragma once
#include <memory>
#include "../Keyboard.h"
#include "../Joypad.h"
#include "../../GettableInputDevice.h"

class GettableDxInputDevice :
	public GettableInputDevice
{
	KeyboardPtr	keyboard;
	JoypadPtr		joypad;

public:

	GettableDxInputDevice();
	~GettableDxInputDevice() = default;

	KeyboardPtr	get_keyboard()	const override;
	JoypadPtr		get_joypad()	const override;
};
