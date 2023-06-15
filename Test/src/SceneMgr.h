#pragma once

#include "TestScene.h"
#include "SceneContext.h"

#include "../../Replay/src/SystemContext.h"
#include "../../Replay/src/VirtualController.h"

class SceneMgr :
	public SceneContext
{
	// ÇªÇÃëºÇÃÉVÅ[ÉìÇÕÇ»Ç¢
	TestScene		scene;
	SystemContext*	system;
	VCtrlPtr		controller;

public:

	SceneMgr() = default;
	SceneMgr( SystemContext* system );
	~SceneMgr() = default;

	bool proc();
	void draw() const;

	// virtual
	VCtrlPtr get_input() const override;
};
