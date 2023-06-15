#pragma once

#include <string>
#include <array>

class Keyboard
{
public:

	// 使えるキー数
	static constexpr int KEY_MAX = 32;
	// 使えるキー名
	inline static const std::array< std::string, Keyboard::KEY_MAX > KEY =
	{{
		"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M",
		"N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z",
		"UP", "RIGHT", "DOWN", "LEFT",
		"LSHIFT", "ESC"
	}};

public:

	Keyboard() = default;
	virtual ~Keyboard() = default;

	virtual bool proc() = 0;
	virtual bool is_input( std::string const& keyname ) const = 0;
};

#include <memory>
using KeyboardPtr = std::shared_ptr< Keyboard >;
