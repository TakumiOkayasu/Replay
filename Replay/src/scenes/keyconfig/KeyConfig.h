#pragma once

#include "../../SystemContext.h"
#include "../../VirtualController.h"
#include "../../OnInputListener.h"
#include <array>
#include <fstream>

class KeyConfig :
	public VirtualController
{
public:

	static constexpr int GAME_USE_KEY = 6;	// ゲーム内で使うキー

private:

	SystemContext*	system;
	std::shared_ptr< OnInputListener >	listener;
	mutable VirtualController::key_type input_state;

	std::fstream	config_file;
	std::array< std::string, KeyConfig::GAME_USE_KEY >	config_pad;
	std::array< std::string, KeyConfig::GAME_USE_KEY >	config_key;

public:

	KeyConfig( SystemContext* system );
	KeyConfig( SystemContext* system, std::shared_ptr< OnInputListener > listener );
	~KeyConfig();

	// 入力状態をNONEにする
	void clear() override;

	key_type get_state() const override;
};
