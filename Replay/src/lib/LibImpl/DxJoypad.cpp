#include <DxLib.h>
#include <array>
#include <algorithm>
#include "DxJoypad.h"

DxJoypad::DxJoypad() :
	pad_state()
{
}

bool DxJoypad::proc()
{
	pad_state = GetJoypadInputState( DX_INPUT_PAD1 );
	return true;
}

static constexpr std::array< int, 6 > dx_joypad_button =
{
	PAD_INPUT_UP,
	PAD_INPUT_RIGHT,
	PAD_INPUT_DOWN,
	PAD_INPUT_LEFT,
	PAD_INPUT_A,
	PAD_INPUT_B,
};

bool DxJoypad::is_input( std::string const& button_name ) const
{
	static const auto first = std::begin( Joypad::BUTTON );
	static const auto last  = std::end(   Joypad::BUTTON );
	const auto it = std::find( first, last, button_name );

	if( it == last ) {
		return false;
	}

	const auto d = std::distance( first, it );
	return ( pad_state & dx_joypad_button[ d ] ) != 0;
}
