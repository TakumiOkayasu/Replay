#pragma once

#include "VirtualController.h"

class OnInputListener
{
public:

	virtual ~OnInputListener() = default;
	// “ü—Íó‘Ô‚ğæ“¾
	virtual void on_input( VirtualController::key_type vctrl ) = 0;
};

