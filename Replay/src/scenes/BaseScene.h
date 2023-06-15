#pragma once

#include <memory>

#include "SceneContext.h"
#include "../lib/KeyInputCount.h"
#include "../scenes/SceneChangeListener.h"

class BaseScene
{
protected:

	SceneContext*			context;
	SceneChangeListener*	listener;

public:

	BaseScene() :
		context( nullptr ),
		listener( nullptr )
	{
	}

	BaseScene( SceneContext* context, SceneChangeListener* listener ) :
		context( context ),
		listener( listener )
	{
	}

	virtual ~BaseScene() = default;

	virtual void initialize() {}
	virtual void finalize() {}
	virtual bool proc()
	{
		KeyInputCount::proc( context->get_input()->get_state() );
		return true;
	}
	virtual void draw() const = 0;
};
