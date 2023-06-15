#pragma once

#include <memory>
#include "GameContext.h"
#include "PlayerContext.h"
#include "PlayerMover.h"
#include "PlayerPrm.h"
#include "../../lib/Utility.h"

class Player :
	public PlayerContext
{
	GameContext*	game;
	std::shared_ptr< PlayerMover >	mover;
	PlayerPrm_t		param;
	Utility::pos_t< int >	pos;

public:

	Player( GameContext* game );
	~Player();

	bool proc();
	void draw() const;

	// virtual PlayerContext

	void up() override;
	void down() override;
	void left() override;
	void right() override;
	PlayerPrm_t get_player_param() const override;
};

