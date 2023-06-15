#include <DxLib.h>
#include <string>

#include "Game.h"
#include "GameContext.h"
#include "Player.h"
#include "../BaseScene.h"
#include "../SceneData.h"
#include "../replay/ReplayRecorder.h"
#include "../replay/ReplayPlayer.h"
#include "../keyconfig/KeyConfig.h"
#include "../../SystemContext.h"
#include "../../VirtualController.h"
#include "../../lib/KeyInputCount.h"

Game::Game( SceneContext* context, SceneChangeListener* listener ) :
	BaseScene( context, listener ),
	game_count( 0U ),
	controller( BaseScene::context->get_input() ),
	player( std::make_shared< Player >( this ) )
{
}

Game::~Game()
{
}

bool Game::proc()
{
	BaseScene::proc();
	++game_count;

	// 前のシーンに戻る
	// 元に戻ることを伝えた後は死ぬ準備のためにリターンする
	if( KeyInputCount::Get( VirtualController::KEY_B ) == 1 ) {
		BaseScene::listener->on_change( SceneData::Scenes::back );
		return true;
	}

	player->proc();

	return true;
}

void Game::draw() const
{
	DrawFormatString( 0, 0, GetColor( 255, 255, 255 ), "GameCnt[%d]", game_count );
	// TODO: この部分を変更し、DxLib臭を消す
	DrawBox(
		GAMEAREA_LEFT_TOP.x, GAMEAREA_LEFT_TOP.y,
		GAMEAREA_LEFT_TOP.x + GAMEAREA_SIZE.x, GAMEAREA_LEFT_TOP.y + GAMEAREA_SIZE.y,
		GetColor( 255, 255, 255 ), FALSE
	);

	/*
	Square
		.coordinate( GAMEAREA_LEFT_TOP )
		.size( GAMEAREA_SIZE )
		.Color( Color::White )
		.is_fill( false )
		.draw();
	*/
	player->draw();
}

Utility::square< int > Game::get_game_area() const
{
	return { GAMEAREA_LEFT_TOP, GAMEAREA_SIZE };
}

unsigned Game::get_game_count() const
{
	return game_count;
}

VCtrlPtr Game::get_input() const
{
	return controller;
}

PlayerPtr Game::get_player_context() const
{
	return player;
}

