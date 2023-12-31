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

		back,	// 前の画面に戻る専用
	};

public:

	SceneContext() = default;
	virtual ~SceneContext() = default;

	virtual VCtrlPtr get_state() const = 0;
};

#include <memory>
using SceneContextPtr = std::shared_ptr< SceneContext >;

