#pragma once
#include <string>
#include <array>

class Joypad
{
public:

	// 最大ボタン数
	static constexpr int PAD_BUTTON_MAX = 28;
	// ボタン名
	inline static const std::array< std::string, 6 > BUTTON =
	{
		"UP", "RIGHT", "DOWN", "LEFT", "A", "B"
	};


public:

	Joypad() = default;
	virtual ~Joypad() = default;

	virtual bool proc() = 0;
	virtual bool is_input( std::string const& button_name ) const = 0;
};

#include <memory>
using JoypadPtr = std::shared_ptr< Joypad >;
