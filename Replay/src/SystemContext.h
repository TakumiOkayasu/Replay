#pragma once

#include <memory>
#include "GettableInputDevice.h"

class SystemContext
{
public:

	SystemContext() = default;
	virtual ~SystemContext() = default;

	virtual std::shared_ptr< GettableInputDevice > get_input_device() const = 0;
};

