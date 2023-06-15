#pragma once

#include <string>
#include <DxLib.h>
#include "../Joypad.h"

class DxJoypad :
	public Joypad
{
	int pad_state;

public:

	DxJoypad();
	~DxJoypad() = default;

	bool proc() override;
	bool is_input( std::string const& button_name ) const override;
};

