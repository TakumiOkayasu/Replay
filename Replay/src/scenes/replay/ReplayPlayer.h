#pragma once
#include <string>
#include <memory>
#include "../../VirtualController.h"
#include "../../lib/Debug.h"
#include "../../lib/Utility.h"
#include "../game/GameContext.h"
#include "../replay/ReplayFileReader.h"

/*
*	���v���C��ǂݍ��݁A���͏�Ԃ�Ԃ��R���g���[���[
*/
class ReplayPlayer :
	public VirtualController
{
	GameContext*	game;
	std::shared_ptr< ReplayFileReader >	reader;

public:

	ReplayPlayer() = default;
	ReplayPlayer( GameContext* game );
	ReplayPlayer( GameContext* game, std::string const& file );
	~ReplayPlayer() = default;

	void clear() override {}
	VirtualController::key_type get_state() const override;

	// ���v���C���ŏ�����Đ��������Ƃ��ɌĂ�
	void from_the_beginning();
};
