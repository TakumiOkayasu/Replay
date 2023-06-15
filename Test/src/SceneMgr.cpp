#include <memory>
#include "SceneMgr.h"
#include "InputConverter.h"

SceneMgr::SceneMgr( SystemContext* system ) :
	system( system ),
	scene( this ),
	controller( std::make_shared< InputConverter >( system ) )
{
}

bool SceneMgr::proc()
{
	scene.proc();
	return true;
}

void SceneMgr::draw() const
{
	scene.draw();
}

// virtual
VCtrlPtr SceneMgr::get_input() const
{
	return controller;
}

