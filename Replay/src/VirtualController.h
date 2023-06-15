#pragma once

/*
*	仮想コントローラー
*	名前がダサすぎるのであとでリネーム
*/
class VirtualController
{
public:

	using key_type = unsigned;

	// 無入力
	static constexpr key_type KEY_NONE = 0;

	// 方向キー
	static constexpr key_type KEY_UP    = 1;
	static constexpr key_type KEY_RIGHT = 2;
	static constexpr key_type KEY_DOWN  = 4;
	static constexpr key_type KEY_LEFT  = 8;

	// A・Bボタン（これは状態によってショットキーやら決定キーになる）
	static constexpr key_type KEY_A = 16;
	static constexpr key_type KEY_B = 32;

public:

	VirtualController() = default;
	virtual ~VirtualController() = default;

	virtual key_type get_state() const = 0;	// キーの入力を返す
	virtual void clear() = 0;
};

// コントローラーヘルパ関数群
/*
class ControllerUtility
{
	inline static VirtualController::key_type now = VirtualController::KEY_NONE;
	inline static VirtualController::key_type old = VirtualController::KEY_NONE;

public:

	ControllerUtility() = default;
	~ControllerUtility() = default;

	static void init()
	{
		now = 0;
		old = 0;
	}

	static void set_state( VirtualController::key_type key )
	{
		old = now;
		now = key;
	}

	// 押した瞬間
	static bool is_trigger( VirtualController::key_type keycode )
	{
		return ( ( old & keycode ) == 0 ) && ( ( now & keycode ) != 0 );
	}

	// 押しっぱなし
	static bool is_pressing( VirtualController::key_type keycode )
	{
		return ( ( old & keycode ) != 0 ) && ( ( now & keycode ) != 0 );
	}

	/*
	*	同時押しを無効化する
	/
	static VirtualController::key_type cancel_input(
		VirtualController::key_type const& input,
		VirtualController::key_type const& first,
		VirtualController::key_type const& second
	)
	{
		auto ret = input;
		if( ( input & first ) && ( input & second ) ) {
			ret &= ~( first | second );
		}
		return ret;
	}
};
*/
#include <memory>
using VCtrlPtr = std::shared_ptr< VirtualController >;


