#pragma once

#include "VirtualController.h"

class OnInputListener
{
public:

	virtual ~OnInputListener() = default;
	// ���͏�Ԃ��擾
	virtual void on_input( VirtualController::key_type vctrl ) = 0;
};

