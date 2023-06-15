#pragma once

#include "../BaseScene.h"
#include "../SceneContext.h"
#include "../../SystemContext.h"
#include "../../VirtualController.h"
#include "../../lib/Debug.h"

class Title :
	public BaseScene
{
	int selecting;

public:

	Title();
	Title( SceneContext* context, SceneChangeListener* listener );
	~Title() = default;

	void initialize() override;
	bool proc() override;
	void draw() const override;
};
