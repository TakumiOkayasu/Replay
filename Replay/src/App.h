#pragma once
#include <memory>
#include "SystemContext.h"
#include "GettableInputDevice.h"
#include "lib/LibImpl/GettableDxInputDevice.h"
#include "scenes/SceneMgr.h"
#include "scenes/title/Title.h"

class App :
	public SystemContext
{
	std::shared_ptr< SceneMgr >				scene;
	std::shared_ptr< GettableInputDevice >	input;

public:

	App();
	~App();

	void run();
	std::shared_ptr< GettableInputDevice > get_input_device() const override;
};
