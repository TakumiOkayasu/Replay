#pragma once

#include "PlayerPrm.h"

class PlayerContext
{
public:

	PlayerContext() = default;
	virtual ~PlayerContext() = default;

	virtual void up() = 0;
	virtual void down() = 0;
	virtual void left() = 0;
	virtual void right() = 0;
	virtual PlayerPrm_t get_player_param() const = 0;
};

#include <memory>
using PlayerPtr = std::shared_ptr< PlayerContext >;
