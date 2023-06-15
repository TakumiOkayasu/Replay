#include "GettableDxInputDevice.h"
#include "../Keyboard.h"
#include "../Joypad.h"
#include "DxKeyboard.h"
#include "DxJoypad.h"
#include <memory>


GettableDxInputDevice::GettableDxInputDevice() :
	keyboard( std::make_shared< DxKeyboard >() ),
	joypad( std::make_shared< DxJoypad >() )
{
}

KeyboardPtr GettableDxInputDevice::get_keyboard() const
{
	return keyboard;
}

JoypadPtr GettableDxInputDevice::get_joypad() const
{
	return joypad;
}

