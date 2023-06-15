#pragma once
#include <fstream>
#include <vector>
#include "../replay/ReplayData.h"
#include "../../OnInputListener.h"
#include "../../VirtualController.h"
#include "../game/GameContext.h"

class ReplayRecorder :
	public OnInputListener
{

	GameContext*	game;
	std::fstream	replay_file;
	std::vector< ReplayData_t > record_data;

public:

	ReplayRecorder( GameContext* game );
	~ReplayRecorder();

	void on_input( VirtualController::key_type input ) override;

private:

	void output_file();
};

