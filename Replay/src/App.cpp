#include <DxLib.h>
#include <memory>
#include "SystemContext.h"
#include "GettableInputDevice.h"
#include "App.h"
#include "lib/LibImpl/GettableDxInputDevice.h"
#include "lib/Keyboard.h"
#include "lib/Joypad.h"
#include "scenes/SceneMgr.h"

App::App() :
	scene( std::make_shared< SceneMgr >( this ) ),
	input( std::make_shared< GettableDxInputDevice >() )

{
	ChangeWindowMode( TRUE );
	DxLib_Init();
	SetDrawScreen( DX_SCREEN_BACK );
}

App::~App()
{
	DxLib_End();
}

void App::run()
{
	while( !ScreenFlip() && !ProcessMessage() && !ClearDrawScreen() ) {
		// “ü—Í‘•’u‚ÌXV
		input->get_keyboard()->proc();
		input->get_joypad()->proc();

		if( input->get_keyboard()->is_input( "ESC" ) ) break;

		if( !scene->proc() ) break;
		scene->draw();
	}
}

std::shared_ptr< GettableInputDevice > App::get_input_device() const
{
	return input;
}
