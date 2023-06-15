#pragma once

#include "../../lib/Utility.h"
#include "../../VirtualController.h"
#include "PlayerContext.h"

class GameContext
{
public:

	GameContext() = default;
	virtual ~GameContext() = default;

	virtual Utility::square< int > get_game_area() const = 0;
	virtual unsigned get_game_count() const = 0;
	virtual VCtrlPtr get_input() const = 0;
	virtual PlayerPtr get_player_context() const = 0;
};
