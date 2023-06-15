#pragma once

#include "PlayerPrm.h"
#include "PlayerContext.h"
#include "../../VirtualController.h"

class PlayerMover
{
	PlayerContext*	player;

public:

	PlayerMover() = default;
	PlayerMover( PlayerContext* p );
	virtual ~PlayerMover() = default;

	void move();
};

