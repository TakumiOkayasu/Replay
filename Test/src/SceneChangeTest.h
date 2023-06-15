#pragma once
#include <DxLib.h>

#include "SceneData.h"
#include "InputConverter.h"
#include "SceneContext.h"
#include "SceneChangeListener.h"

#include "../../Replay/src/SystemContext.h"
#include "../../Replay/src/GettableInputDevice.h"
#include "../../Replay/src/lib/Joypad.h"
#include "../../Replay/src/lib/Keyboard.h"
#include "../../Replay/src/lib/Debug.h"
#include "../../Replay/src/lib/LibImpl/GettableDxInputDevice.h"


class BaseScene
{
protected:

	SceneContext* context;
	SceneChangeListener* listener;
	std::string scene_name;

public:

	BaseScene() = default;
	BaseScene( std::string const& name, SceneContext* context, SceneChangeListener* listener ) :
		context( context ),
		listener( listener ),
		scene_name( name )
	{
	}
	virtual ~BaseScene() = default;

	virtual bool proc()
	{
		//ControllerUtility::set_state( context->get_input()->get_state() );
		return true;
	}

	virtual void draw() const
	{
		DrawFormatString( 10, 10, GetColor( 255, 255, 255 ), "%s", scene_name.c_str() );
	}
};

class GameScene :
	public BaseScene
{
public:

	GameScene( SceneContext* context, SceneChangeListener* listener ) :
		BaseScene( "GameScene", context, listener )
	{
	}

	~GameScene() = default;

	bool proc() override
	{
		BaseScene::proc();
		const auto input = BaseScene::context->get_input()->get_state();

		if( ControllerUtility::is_trigger( VirtualController::KEY_B ) ) {
			BaseScene::listener->on_change( SceneData::Scenes::back );
		}

		return true;
	}

	void draw() const override
	{
		BaseScene::draw();
		DrawFormatString( 10, 26, GetColor( 255, 255, 255 ), "Xキーで前のシーンに戻ります" );
	}
};

class TitleScene :
	public BaseScene
{
	int selecting;

public:

	TitleScene( SceneContext* context, SceneChangeListener* listener ) :
		BaseScene( "TitleScene", context, listener ),
		selecting( 0 )
	{
	}

	~TitleScene() = default;

	bool proc() override
	{
		BaseScene::proc();
		static constexpr SceneData::Scenes scenes[] = { SceneData::Scenes::game,SceneData::Scenes::exit };
		const auto input = BaseScene::context->get_input()->get_state();

		if( ControllerUtility::is_trigger( VirtualController::KEY_UP ) ) {
			selecting--;
		}

		if( ControllerUtility::is_trigger( VirtualController::KEY_DOWN ) ) {
			selecting++;
			// BaseScene::listener->on_change( SceneData::Scenes::exit );
		}

		selecting %= 2;

		if( ControllerUtility::is_trigger( VirtualController::KEY_A ) ) {
			BaseScene::listener->on_change( scenes[ selecting ] );
		}

		return true;
	}

	void draw() const override
	{
		BaseScene::draw();

		static constexpr const char* scene_names[] = { "Game Scene", "   Exit   " };
		static constexpr int center_x = ( 640 - 11 * 8 ) / 2;
		static constexpr int center_y = 480 / 2;

		for( int i=0 ; i < 2 ; ++i ) {
			DrawFormatString(
				center_x, center_y + 16 * i,
				( i == selecting ) ? GetColor( 197, 36, 128 ) : GetColor( 255, 255, 255 ),
				"%s", scene_names[ i ]
			);
		}
	}
};

class ExitScene :
	public BaseScene
{
public:

	ExitScene( SceneContext* context, SceneChangeListener* listener ) :
		BaseScene( "Exit", context, listener )
	{
	}

	~ExitScene() {}

	bool proc() override { return false; }
	void draw() const override {}
};

class SceneMgr :
	public SceneContext,
	public SceneChangeListener
{

	VCtrlPtr input;
	std::stack< std::shared_ptr< BaseScene > > scenes;

public:

	SceneMgr( SystemContext* system ) :
		input( std::make_shared< InputConverter >( system ) ),
		scenes()
	{
		scenes.emplace( std::make_shared< TitleScene >( this, this ) );
	}

	~SceneMgr() = default;

	bool proc()
	{
		return !scenes.empty() ? scenes.top()->proc() : false;
	}

	void draw() const
	{
		scenes.top()->draw();
	}

	void on_change( SceneData::Scenes next ) override
	{
		switch( next ) {
		case SceneData::Scenes::back:
			{
				// pop 可能なら
				if( scenes.size() > 1 ) {
					scenes.pop();
				}
			}
			break;

		case SceneData::Scenes::game:
			{
				scenes.emplace( std::make_shared< GameScene >( this, this ) );
			}
			break;

		case SceneData::Scenes::exit:
			{
				scenes.emplace( std::make_shared< ExitScene >( this, this ) );
			}
			break;
		}

	}

	VCtrlPtr get_input() const override
	{
		return input;
	}
};
