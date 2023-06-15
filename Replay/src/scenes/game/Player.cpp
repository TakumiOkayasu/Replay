#include <DxLib.h>
#include <memory>

#include "Player.h"
#include "../../lib/Debug.h"

Player::Player( GameContext* game ) :
	game( game ),
	mover( std::make_shared< PlayerMover >( this ) ),
	param( 5, 1, "" ),
	pos()
{
	const auto area = game->get_game_area();

	pos.x = area.left_top.x + area.size.x / 2;
	pos.y = area.left_top.y + area.size.y * 3 / 4;
}

Player::~Player()
{
}

bool Player::proc()
{
	static const auto area = game->get_game_area();
	static const Utility::pos_t< int > right_down
	{
		area.left_top.x + area.size.x,
		area.left_top.y + area.size.y
	};

	mover->move();

	pos.x = Utility::clamp( pos.x, area.left_top.x, right_down.x );
	pos.y = Utility::clamp( pos.y, area.left_top.y, right_down.y );
	
	return true;
}

void Player::draw() const
{
	// TODO : ここのDxLib依存を辞める
	// さらに言うと、PlayerParameterなどのクラス/構造体にまとめるべきで
	// ParameterReader等を介して設定するとよいと思われる
	DrawCircle( pos.x, pos.y, param.hit_range, GetColor( 255, 0, 0 ) );
	/*
	circle
		.coordinate( pos )
		.radius( 5 )
		.color( Color::White )
		.draw();
	*/
}


void Player::up()
{
	pos.y -= param.move_speed;
}

void Player::down()
{
	pos.y += param.move_speed;
}

void Player::left()
{
	pos.x -= param.move_speed;
}

void Player::right()
{
	pos.x += param.move_speed;
}

PlayerPrm_t Player::get_player_param() const
{
	return param;
}

