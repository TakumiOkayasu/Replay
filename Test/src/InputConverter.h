#pragma once

#include "../../Replay/src/VirtualController.h"
#include "../../Replay/src/SystemContext.h"

// test 用なので決め打ちでやる
class InputConverter :
	public VirtualController
{
	SystemContext*	system;

public:

	InputConverter( SystemContext* system );
	~InputConverter() = default;

	VirtualController::key_type get_state() const override;
};
