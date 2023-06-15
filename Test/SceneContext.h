#pragma once

#include "../Replay/src/VirtualController.h"
#include "src/SceneChangeListener.h"

class SceneContext
{
public:

	enum class Scenes
	{
		title,
		game,
		replay_play,
		key_config,
		exit,

		back,	// ‘O‚Ì‰æ–Ê‚É–ß‚éê—p
	};

public:

	SceneContext() = default;
	virtual ~SceneContext() = default;

	virtual VCtrlPtr get_state() const = 0;
};

#include <memory>
using SceneContextPtr = std::shared_ptr< SceneContext >;

