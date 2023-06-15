#include "../../VirtualController.h"
#include "../game/GameContext.h"
#include "../../lib/Debug.h"
#include "../../lib/Utility.h"
#include "../../lib/File.h"
#include "../replay/ReplayPlayer.h"
#include "../replay/ReplayFileReader.h"

ReplayPlayer::ReplayPlayer( GameContext * game ) :
	game( game ),
	reader()
{
}

ReplayPlayer::ReplayPlayer( GameContext* game, std::string const& file ) :
	game( game ),
	reader()
{
	// ここはもっときれいにしたい
	reader = std::make_shared< ReplayFileReader >( file );
	reader->read();
}

VirtualController::key_type ReplayPlayer::get_state() const
{
	const auto data = reader->get_replay_data();
	const auto now  = game->get_game_count();
	// 現在のゲームカウントと読み込んだリプレイのカウントが同じなら入力情報を
	// そうでないなら０（無入力）を返す
	// 現在のゲームカウントなら、次のデータに進める
	// 
	if( data.game_count == now ) {
		reader->next();
		return data.input;
	}

	return VirtualController::KEY_NONE;
}

void ReplayPlayer::from_the_beginning()
{
	reader->from_the_beginning();
}

