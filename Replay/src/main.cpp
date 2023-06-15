#include "App.h"
#include "lib/Debug.h"

int WINAPI WinMain( HINSTANCE, HINSTANCE, LPSTR, int )
{
	debug_console dbc;
	App {}.run();
	return 0;
}

