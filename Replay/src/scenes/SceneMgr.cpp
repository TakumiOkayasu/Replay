#include <string>
#include <DxLib.h>

#include "SceneMgr.h"
#include "SceneData.h"
#include "BaseScene.h"
#include "game/Game.h"
#include "title/Title.h"
#include "keyconfig/KeyConfig.h"
#include "replay/ReplayPlayer.h"
#include "../SystemContext.h"
#include "../lib/KeyInputCount.h"

// exit class は何もしないので外部に公開する必要がないのでここで実装
// ゲーム終了も一つのシーンとして、こうする
class Exit :
	public BaseScene
{
public:

	Exit( SceneContext* context, SceneChangeListener* listener ) :
		BaseScene( context, listener ) 
	{
	}
	~Exit() = default;

	void initialize() override {}
	void finalize() override {}
	bool proc() override { return false; }
	void draw() const override {}
};

SceneMgr::SceneMgr( SystemContext* system ) :
	system( system ),
	controller( std::make_shared< KeyConfig >( system ) ),	// デフォルトのコントローラー
	replay_ctrl( std::make_shared< ReplayPlayer >() ),		// リプレイを見る場合はここでいろいろやる
	scenes(),
	scene( SceneData::Scenes::title )	// 最初はタイトル画面だよね
{
	scenes.push( std::make_shared< Title >( this, this ) );
}

void SceneMgr::initialize()
{
	scenes.top()->initialize();
}

void SceneMgr::finalize()
{
	scenes.top()->finalize();
}

bool SceneMgr::proc()
{
	// 終了させるときはproc()がfalseを返すd
	return scenes.top()->proc();
}

void SceneMgr::draw() const
{
	scenes.top()->draw();
}

VCtrlPtr SceneMgr::get_input() const
{
	if( scene == SceneData::Scenes::replay_play ) {
		// return replay_ctrl;
	}

	return controller;
}

class NullScene : public BaseScene
{
public:

	NullScene( SceneContext* context, SceneChangeListener* listener ) :
		BaseScene( context, listener )
	{}
	virtual ~NullScene() = default;

	bool proc() override
	{
		BaseScene::proc();

		if( KeyInputCount::Get( VirtualController::KEY_B ) ) {
			BaseScene::listener->on_change( SceneData::Scenes::back );
		}

		return true;
	}

	void draw() const override
	{
		static constexpr auto message = R"(This scene is not impremented.Press X Key to back.)";
		DrawFormatString( 90, 16, GetColor( 255, 255, 255 ), "%s", message );
	}
};

void SceneMgr::on_change( SceneData::Scenes next )
{
	scenes.top()->finalize();	// 前のシーンを終了させる

	switch( next ) {
	case SceneData::Scenes::back:	// 前のシーンに戻る
		{
			if( scenes.size() > 1 ) {
				scenes.pop();
			}
		}
		break;

	case SceneData::Scenes::game:
		{
			scenes.emplace( std::make_shared< Game >( this, this ) );
		}
		break;

	case SceneData::Scenes::replay_play:
		{
			scenes.emplace( std::make_shared< NullScene >( this, this ) );
		}
		break;

	case SceneData::Scenes::key_config:
		{
			scenes.emplace( std::make_shared< NullScene >( this, this ) );
		}
		break;

	case SceneData::Scenes::exit:
		{
			scenes.emplace( std::make_shared< Exit >( this, this ) );
		}
		break;

	default:
		{
		}
		break;
	}

	scene = next; // シーンを設定
	scenes.top()->initialize();
}
