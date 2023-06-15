#include <functional>

#include "PlayerMover.h"
#include "PlayerContext.h"
#include "PlayerPrm.h"
#include "../../VirtualController.h"
#include "../../lib/Debug.h"
#include "../../lib/KeyInputCount.h"

PlayerMover::PlayerMover( PlayerContext* p ) :
	player( p )
{
}

void PlayerMover::move()
{
	if( KeyInputCount::Get( VirtualController::KEY_UP ) != 0 ) { player->up(); }
	if( KeyInputCount::Get( VirtualController::KEY_DOWN ) != 0 ) { player->down(); }
	if( KeyInputCount::Get( VirtualController::KEY_LEFT ) != 0 ) { player->left(); }
	if( KeyInputCount::Get( VirtualController::KEY_RIGHT ) != 0 ) { player->right(); }
}
