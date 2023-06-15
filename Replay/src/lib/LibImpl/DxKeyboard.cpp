#include <DxLib.h>
#include <array>
#include <algorithm>
#include <string>
#include "../../lib/Keyboard.h"
#include "DxKeyboard.h"

bool DxKeyboard::proc()
{
	GetHitKeyStateAll( keybuff_ );
	return true;
}

/*
*	もうちょっとうまくできそう
*	もしかしたら仕様を変更するかも
*	とりあえず使いそうなキーを用意
*	思いつきで書いてる
*/

#define CNV(a)	KEY_INPUT_##a
static constexpr std::array< int, Keyboard::KEY_MAX > dx_keymap =
{
	// alphabet
	CNV( A ), CNV( B ), CNV( C ), CNV( D ), CNV( E ), CNV( F ), CNV( G ),
	CNV( H ), CNV( I ), CNV( J ), CNV( K ), CNV( L ), CNV( M ), CNV( N ),
	CNV( O ), CNV( P ), CNV( Q ), CNV( R ), CNV( S ), CNV( T ), CNV( U ),
	CNV( V ), CNV( W ), CNV( X ), CNV( Y ), CNV( Z ),
	// dir
	CNV( UP ), CNV( RIGHT ), CNV( DOWN ), CNV( LEFT ),
	// other
	CNV( LSHIFT ), CNV( ESCAPE )
};
#undef CNV

bool DxKeyboard::is_input( std::string const& keyname ) const
{
	static const auto first = std::begin( Keyboard::KEY );
	static const auto last  = std::end(   Keyboard::KEY );
	const auto it = std::find( first, last, keyname );

	if( it == last ) {
		return false;
	}

	const auto d = std::distance( first, it );
	return keybuff_[ dx_keymap[ d ] ] != 0;
}

