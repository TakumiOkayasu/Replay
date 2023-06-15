#include <fstream>
#include <filesystem>
#include "ReplayRecorder.h"
#include "../../OnInputListener.h"
#include "../../VirtualController.h"
#include "../game/GameContext.h"
#include "../../lib/Debug.h"
#include "../../lib/Utility.h"

namespace fs = std::experimental::filesystem;

static const std::string rep_file = "rep0.rpy";

ReplayRecorder::ReplayRecorder( GameContext* game ) :
	game( game ),
	replay_file(),
	record_data()
{
	if( fs::exists( rep_file ) ) {
		fs::remove( rep_file );
	}

	Utility::make_new_file( rep_file );
	printf( "リプレイファイル作成\n" );
}

ReplayRecorder::~ReplayRecorder()
{
	this->output_file();
}

void ReplayRecorder::on_input( VirtualController::key_type input )
{
	record_data.emplace_back( input, game->get_game_count() );
}

/*
*	TODO ここはReplayFileWriterなどが受け持つべき
*/
void ReplayRecorder::output_file()
{
	replay_file.open( rep_file, std::ios::binary | std::ios::out );

	for( auto&& e : record_data ) {
		replay_file.write( reinterpret_cast< const char* >( &e.input ), sizeof( e.input ) );
		replay_file.write( reinterpret_cast< const char* >( &e.game_count ), sizeof( e.game_count ) );
	}

	replay_file.close();
}

