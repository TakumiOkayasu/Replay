#include "InputConverter.h"
#include <DxLib.h>

InputConverter::InputConverter( SystemContext* system ) :
	system( system )
{
}

static constexpr int USABLE_KEY_NUM = 6;

// keyboard joypad ‹¤’Ê
static constexpr
const char* KeyNames[ USABLE_KEY_NUM ] =
{
	"UP", "RIGHT", "DOWN", "LEFT", "Z", "X"
};

static constexpr
VirtualController::key_type VirtualKeyCodes[ USABLE_KEY_NUM ] =
{
	VirtualController::KEY_UP,
	VirtualController::KEY_RIGHT,
	VirtualController::KEY_DOWN,
	VirtualController::KEY_LEFT,
	VirtualController::KEY_A,
	VirtualController::KEY_B,
};

VirtualController::key_type InputConverter::get_state() const
{
	const auto keyboard = system->get_input_device()->get_keyboard();
	const auto joypad   = system->get_input_device()->get_joypad();

	auto input = VirtualController::KEY_NONE;

	for( int i=0 ; i < USABLE_KEY_NUM ; ++i ) {
		if( keyboard->is_input( KeyNames[ i ] ) ||
			joypad->is_input( KeyNames[ i ] ) )
		{
			input |= VirtualKeyCodes[ i ];
		}
	}

	return input;
}
