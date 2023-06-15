#pragma once
#include <string>
#include <cstddef>

class File
{
	std::string		file_name;
public:

	File();
	File( std::string const& filename );
	File( File const& file ) = delete;
	~File();

	// ファイルサイズを取得する
	std::uintmax_t size() const;
	// ファイル名を取得する
	const std::string& get_file_name() const;
};

