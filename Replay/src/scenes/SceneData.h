#pragma once

class SceneData final
{
public:

	SceneData() = default;
	~SceneData() = default;

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

