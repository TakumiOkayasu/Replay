#include <DxLib.h>
#include <memory>
#include <stack>
#include <string>

#include "SceneData.h"
#include "InputConverter.h"
#include "SceneContext.h"
#include "SceneChangeListener.h"

#include "SceneChangeTest.h"
#include "../Replay/Replay/src/lib/KeyInputCount.h"

class App :
	public SystemContext
{
	std::shared_ptr< GettableInputDevice >	device;
	//std::shared_ptr< GettableKeyInputCount > key_input_count;

public:

	App() :
		device( std::make_shared< GettableDxInputDevice >() )
		//, key_input_count( std::make_shared< GettableKeyInputCount >() )
	{
		ChangeWindowMode( TRUE );
		DxLib_Init();
		SetDrawScreen( DX_SCREEN_BACK );
	}

	~App()
	{
		DxLib_End();
	}

	void run()
	{
		while( !ProcessMessage() ) {
			ClearDrawScreen();

			device->get_keyboard()->proc();
			device->get_joypad()->proc();

			if( device->get_keyboard()->is_input( "ESC" ) ) break;

			ScreenFlip();
		}
	}

	// virtual
	std::shared_ptr< GettableInputDevice >
	get_input_device() const override
	{
		return device;
	}
};

int WINAPI WinMain( HINSTANCE, HINSTANCE, LPSTR, int )
{
	debug_console dbc {};
	App app {};
	app.run();
	return 0;
}

