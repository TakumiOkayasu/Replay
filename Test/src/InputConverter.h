#pragma once

#include "../../Replay/src/VirtualController.h"
#include "../../Replay/src/SystemContext.h"

// test �p�Ȃ̂Ō��ߑł��ł��
class InputConverter :
	public VirtualController
{
	SystemContext*	system;

public:

	InputConverter( SystemContext* system );
	~InputConverter() = default;

	VirtualController::key_type get_state() const override;
};
