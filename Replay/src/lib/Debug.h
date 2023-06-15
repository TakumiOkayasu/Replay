#pragma once
#if _DEBUG
#include <Windows.h>
#include <utility>
#include <iostream>

class debug_console
{
	std::FILE*	console;
public:

	debug_console() :
		console( nullptr )
	{
		AllocConsole();
		freopen_s( &console, "CONOUT$", "w", stdout );
		freopen_s( &console, "CONIN$",  "r", stdin );
	}
	~debug_console()
	{
		FreeConsole();
	}

	template< typename T >
	static void println( T&& t )
	{
		std::cout << t << std::endl;
	}

	template< typename T >
	static void print( T&& t )
	{
		std::cout << t;
	}

	template< typename Head, typename... Tail >
	static void print( Head&& h, Tail&&... tail )
	{
		print( h );
		print( tail... );
		println( "" );
	}
};

#else

class debug_console
{
public:

	debug_console() = default;
	~debug_console() = default;

	static void print( ... ) {}
};

#endif
