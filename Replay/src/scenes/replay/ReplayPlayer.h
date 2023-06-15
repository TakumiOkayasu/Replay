#pragma once
#include <string>
#include <memory>
#include "../../VirtualController.h"
#include "../../lib/Debug.h"
#include "../../lib/Utility.h"
#include "../game/GameContext.h"
#include "../replay/ReplayFileReader.h"

/*
*	リプレイを読み込み、入力状態を返すコントローラー
*/
class ReplayPlayer :
	public VirtualController
{
	GameContext*	game;
	std::shared_ptr< ReplayFileReader >	reader;

public:

	ReplayPlayer() = default;
	ReplayPlayer( GameContext* game );
	ReplayPlayer( GameContext* game, std::string const& file );
	~ReplayPlayer() = default;

	void clear() override {}
	VirtualController::key_type get_state() const override;

	// リプレイを最初から再生したいときに呼ぶ
	void from_the_beginning();
};
