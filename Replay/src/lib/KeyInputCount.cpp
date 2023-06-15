#include "KeyInputCount.h"
#include "../VirtualController.h"
#include "../scenes/keyconfig/KeyConfig.h"
#include "../lib/Debug.h"

static
std::array< VirtualController::key_type, KeyConfig::GAME_USE_KEY > input_counter;


// TODO KeyConfig.cpp に全く同じものがあるので、後でどうにかする
static constexpr
VirtualController::key_type key_map[ KeyConfig::GAME_USE_KEY ] =
{
	VirtualController::KEY_UP,
	VirtualController::KEY_RIGHT,
	VirtualController::KEY_DOWN,
	VirtualController::KEY_LEFT,
	VirtualController::KEY_A,
	VirtualController::KEY_B,
};

void KeyInputCount::init()
{
	std::fill(
		std::begin( input_counter ),
		std::end( input_counter ),
		VirtualController::KEY_NONE
	);
}

// static
bool KeyInputCount::proc( VirtualController::key_type key )
{
	for( int i=0 ; i < KeyConfig::GAME_USE_KEY ; ++i ) {
		if( key & key_map[ i ] ) {
			++input_counter[ i ];
		}
		else {
			input_counter[ i ] = 0;
		}
	}

	return true;
}

// static
unsigned KeyInputCount::Get( VirtualController::key_type key )
{
	static constexpr auto first = std::begin( key_map );
	static constexpr auto last  = std::end( key_map );
	const auto it = std::find( first, last, key );

	if( it == last ) {
		std::runtime_error { "ERROR!! キーコードがおかしい" };
	}

	const auto d = std::distance( first, it );
	return input_counter[ d ];
}
