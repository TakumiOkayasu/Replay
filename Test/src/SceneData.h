#pragma once

class SceneData
{
public:

	SceneData() = default;
	~SceneData() = default;

public:

	enum class Scenes
	{
		title,
		game,
		replay_play,
		key_config,
		exit,

		back,	// �O�̉�ʂɖ߂��p
	};
};
