#pragma once

#include "SceneData.h"

class SceneChangeListener
{
public:

	SceneChangeListener() = default;
	virtual ~SceneChangeListener() = default;

	virtual void on_change( SceneData::Scenes next ) = 0;
};

