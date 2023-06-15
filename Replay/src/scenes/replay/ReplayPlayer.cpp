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
	// �����͂����Ƃ��ꂢ�ɂ�����
	reader = std::make_shared< ReplayFileReader >( file );
	reader->read();
}

VirtualController::key_type ReplayPlayer::get_state() const
{
	const auto data = reader->get_replay_data();
	const auto now  = game->get_game_count();
	// ���݂̃Q�[���J�E���g�Ɠǂݍ��񂾃��v���C�̃J�E���g�������Ȃ���͏���
	// �����łȂ��Ȃ�O�i�����́j��Ԃ�
	// ���݂̃Q�[���J�E���g�Ȃ�A���̃f�[�^�ɐi�߂�
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

