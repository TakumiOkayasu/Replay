#include <string>
#include <array>
#include <utility>
#include <DxLib.h>
#include <bitset>

#include "Title.h"
#include "../SceneData.h"
#include "../BaseScene.h"
#include "../keyconfig/KeyConfig.h"
#include "../../VirtualController.h"
#include "../../lib/Utility.h"
#include "../../lib/Debug.h"
#include "../../lib/KeyInputCount.h"

static constexpr int selectable_num = 4;
static constexpr int scene_name_length = 14;
static constexpr int font_size = 16;

struct SceneInfo_t
{
	std::string scene_name;
	bool		is_selecting;
	SceneData::Scenes	scene_type;
};

static
std::array< SceneInfo_t, selectable_num > ScenesInfo
{{
	{ "Replay Record",  true, SceneData::Scenes::game },
	{ "Replay  Play ", false, SceneData::Scenes::replay_play },
	{ "  KeyConfig  ", false, SceneData::Scenes::key_config },
	{ "     Exit    ", false, SceneData::Scenes::exit }
}};

Title::Title()
{
	this->initialize();
}

Title::Title( SceneContext* context, SceneChangeListener* listener ) :
	BaseScene( context, listener ),
	selecting( 0 )
{
	this->initialize();
}

void Title::initialize()
{
}

bool Title::proc()
{
	BaseScene::proc();

	if( KeyInputCount::Get( VirtualController::KEY_UP ) == 1 ) {
		--selecting;
	}

	if( KeyInputCount::Get( VirtualController::KEY_DOWN ) == 1 ) {
		++selecting;
	}

	// �͈͓��Ń��[�v������
	selecting = Utility::wrap_around( selecting, 0, selectable_num );

	// �I�𒆂��ǂ����̔���
	for( int i = 0 ; i < selectable_num ; ++i ) {
		ScenesInfo[ i ].is_selecting = ( i == selecting );
	}

	// �L�����Z���L�[�������ꂽ��
	if( KeyInputCount::Get( VirtualController::KEY_B ) == 1 ) {
		// "Exit" ���I�𒆂ɃL�����Z���L�[�������ꂽ��I������
		if( selecting == selectable_num - 1 ) {
			BaseScene::listener->on_change( SceneData::Scenes::exit );
		}
		else {
			// �����I�� "Exit" �Ɉړ�����
			selecting = selectable_num - 1;
		}
	}

	// ����L�[�������ꂽ�玟�̃V�[����
	if( KeyInputCount::Get( VirtualController::KEY_A ) == 1 ) {
		BaseScene::listener->on_change( ScenesInfo[ selecting ].scene_type );
	}

	return true;
}

void Title::draw() const
{
	// TODO �����ŏ����ׂ��łȂ�
	static constexpr int center_x = ( 640 - scene_name_length * 8 )/ 2;
	static constexpr int center_y = 480 / 2;

	static const auto selecting_color     = GetColor( 197,  36, 128 );
	static const auto not_selecting_color = GetColor( 255, 255, 255 );

	int draw_y_pos = 0;

	for( auto&& e : ScenesInfo ) {
		DrawFormatString(
			center_x, center_y + draw_y_pos,
			e.is_selecting ? selecting_color : not_selecting_color,
			"%s",
			e.scene_name.c_str()
		);

		draw_y_pos += font_size;
	}
}
