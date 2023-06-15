#pragma once
#include "../../VirtualController.h"

struct ReplayData_t
{
	VirtualController::key_type input;
	unsigned	game_count;

	ReplayData_t() :
		input(),
		game_count()
	{
	}

	ReplayData_t( VirtualController::key_type input, unsigned cnt ) :
		input( input ),
		game_count( cnt )
	{
	}
};
