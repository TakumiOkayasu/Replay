#pragma once

#include "VirtualController.h"

class OnInputListener
{
public:

	virtual ~OnInputListener() = default;
	// 入力状態を取得
	virtual void on_input( VirtualController::key_type vctrl ) = 0;
};

