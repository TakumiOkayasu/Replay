#pragma once

#include <stack>
#include <memory>

#include "SceneChangeListener.h"
#include "SceneContext.h"
#include "BaseScene.h"
#include "SceneData.h"
#include "../SystemContext.h"
#include "../VirtualController.h"

class SceneMgr :
	public SceneContext,
	public SceneChangeListener
{
	SystemContext*		system;
	VCtrlPtr			controller, replay_ctrl;
	std::stack< std::shared_ptr< BaseScene > > scenes;
	SceneData::Scenes scene;

public:

	SceneMgr() = default;
	SceneMgr( SystemContext* system );
	~SceneMgr() = default;

	void initialize();
	void finalize();
	bool proc();
	void draw() const;

	// virtual
	VCtrlPtr get_input() const override;
	void on_change( SceneData::Scenes next ) override;
};
