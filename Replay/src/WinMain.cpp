#include "App.h"
#include "lib/Debug.h"

int WINAPI WinMain( HINSTANCE, HINSTANCE, LPSTR, int )
{
	debug_console dbc;	// デバッグ用コンソールを出します
	App {}.run();		// Application を実行します

	return 0;
}

