#pragma once

#include <DxLib.h>
#include <string>
#include "../Keyboard.h"

class DxKeyboard :
	public Keyboard
{
	static constexpr int KEY_MAX = 256;
	char	keybuff_[ KEY_MAX ];

public:

	DxKeyboard() = default;
	~DxKeyboard() = default;

	bool proc() override;
	bool is_input( std::string const& keyname ) const override;
};

