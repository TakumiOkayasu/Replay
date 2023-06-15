#include <array>
#include <memory>
#include "KeyConfig.h"
#include "../../lib/Joypad.h"
#include "../../lib/Keyboard.h"
#include "../../lib/Utility.h"
#include "../../lib/Debug.h"
#include "../../VirtualController.h"
#include "../../OnInputListener.h"

static const std::string config_file_name = "key.config";

static const
std::array< std::string, KeyConfig::GAME_USE_KEY > default_key_name =
{
	"UP", "RIGHT", "DOWN", "LEFT", "Z", "X"
};

static const
std::array< std::string, KeyConfig::GAME_USE_KEY > default_pad_button =
{
	"UP", "RIGHT", "DOWN", "LEFT", "A", "B"
};

class dummy : public OnInputListener
{
public:

	dummy() = default;
	~dummy() = default;

	void on_input( VirtualController::key_type ) override {}
};

// OnInputListener���K�v�Ȃ��ꍇ
KeyConfig::KeyConfig( SystemContext* system ) :
	system( system ),
	listener( std::make_shared< dummy >() ),
	input_state( VirtualController::KEY_NONE ),
	config_file( config_file_name ),
	config_pad(),
	config_key()
{
	// �Ȃ��Ȃ���
	if( config_file.fail() ) {
		debug_console::println( "config�t�@�C�����Ȃ���������쐬������" );
		std::ofstream ofs( config_file_name );
		for( int i=0 ; i < GAME_USE_KEY ; ++i ) {
			ofs << default_key_name[ i ] << " " << default_pad_button[ i ] << " \n";
		}
	} else {
		debug_console::println( "config�t�@�C���ǂݍ���" );
		for( int i=0 ; i < GAME_USE_KEY ; ++i ) {
			std::string buf {};
			std::getline( config_file, buf );
			const auto splited = std::move( Utility::split( buf ) );
			config_key[ i ] = std::move( splited[ 0 ] );
			config_pad[ i ] = std::move( splited[ 1 ] );
		}
	}
}

// TODO �����̓��e�I�ɂ͕ʃN���X�ōs���ׂ�������������Ă���.�v���P.
KeyConfig::KeyConfig( SystemContext* system, std::shared_ptr< OnInputListener > listener ) :
	system( system ),
	listener( listener ),
	input_state( VirtualController::KEY_NONE ),
	config_file( config_file_name ),
	config_pad(),
	config_key()
{
	// �Ȃ��Ȃ���
	if( config_file.fail() ) {
		debug_console::print( "config�t�@�C�����Ȃ���������쐬������" );
		std::ofstream ofs( config_file_name );
		for( int i=0 ; i < GAME_USE_KEY ; ++i ) {
			ofs << default_key_name[ i ] << " " << default_pad_button[ i ] << " \n";
		}
	}
	else {
		debug_console::print( "config�t�@�C���ǂݍ���" );
		for( int i=0 ; i < GAME_USE_KEY && !config_file.eof() ; ++i ) {
			std::string buf {};
			std::getline( config_file, buf );
			const auto splited = std::move( Utility::split( buf ) );
			config_key[ i ] = std::move( splited[ 0 ] );
			config_pad[ i ] = std::move( splited[ 1 ] );
		}
	}
}

KeyConfig::~KeyConfig()
{
}

static constexpr
VirtualController::key_type key_map[ KeyConfig::GAME_USE_KEY ] =
{
	VirtualController::KEY_UP,
	VirtualController::KEY_RIGHT,
	VirtualController::KEY_DOWN,
	VirtualController::KEY_LEFT,
	VirtualController::KEY_A,
	VirtualController::KEY_B,
};

void KeyConfig::clear()
{
	input_state = VirtualController::KEY_NONE;
}

VirtualController::key_type KeyConfig::get_state() const
{
	// �L�[�{�[�h�ƃQ�[���p�b�h�̓��͂��擾
	const auto keyboard = system->get_input_device()->get_keyboard();
	const auto joypad   = system->get_input_device()->get_joypad();

	input_state = VirtualController::KEY_NONE;

	for( int i=0 ; i < GAME_USE_KEY ; ++i ) {
		if(
			keyboard->is_input( config_key[ i ] ) ||
			joypad  ->is_input( config_pad[ i ] )
		) {
			input_state |= key_map[ i ];
		}
	}

	// �㉺�L�[��������������
/*	input = ControllerUtility::cancel_input(
		input,
		VirtualController::KEY_UP,
		VirtualController::KEY_DOWN
	);

	// ���E�L�[��������������
	input = ControllerUtility::cancel_input(
		input,
		VirtualController::KEY_LEFT,
		VirtualController::KEY_RIGHT
	);*/

	// ���͂���������Γ��͏�Ԃ�ʒm����
	if( input_state != VirtualController::KEY_NONE ) {
		// �O�̃V�[���ɖ߂�{�^���͋L�^���Ȃ�
		listener->on_input( input_state & ~VirtualController::KEY_B );
	}

	return input_state;
}

