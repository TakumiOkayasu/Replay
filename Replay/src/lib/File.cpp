#include "File.h"
#include "Utility.h"
#include "Debug.h"
#include <string>
#include <cstddef>
#include <filesystem>

// ‚±‚±‚ç‚Ö‚ñ‚Ç‚¤‚É‚©‚µ‚½‚¢‚µA‘‚­ Visual Studio ‚Í C++17 ‚ÉŠ®‘S‘Î‰‚µ‚ë
#if 1
	namespace fs = std::experimental::filesystem;
#else
	using fs = std::filesystem;
#endif

File::File() :
	file_name()
{
}

File::File( std::string const& filename ) :
	file_name( filename )
{
}

File::~File()
{
}

std::uintmax_t File::size() const
{
	return fs::file_size( file_name );
}

const std::string& File::get_file_name() const
{
	return file_name;
}
