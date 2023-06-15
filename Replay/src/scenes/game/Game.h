#pragma once

#include "GameContext.h"
#include "Player.h"
#include "PlayerContext.h"
#include "../BaseScene.h"
#include "../keyconfig/KeyConfig.h"
#include "../../SystemContext.h"
#include "../../VirtualController.h"
#include "../../lib/Debug.h"

class Game :
	public GameContext,
	public BaseScene
{
	static constexpr Utility::pos_t< int >	GAMEAREA_SIZE     = { 384, 448 };
	static constexpr Utility::pos_t< int >	GAMEAREA_LEFT_TOP = { 128,  16 };

	unsigned		game_count;
	VCtrlPtr		controller;
	std::shared_ptr< Player >	player;

public:

	Game( SceneContext* context, SceneChangeListener* listener );
	~Game();

	bool proc() override;
	void draw() const override;

	// virtual

	Utility::square< int > get_game_area() const override;
	unsigned get_game_count() const override;
	VCtrlPtr get_input() const override;
	PlayerPtr get_player_context() const override;
};

