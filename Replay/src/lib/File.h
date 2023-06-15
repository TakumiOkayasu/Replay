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

	// �t�@�C���T�C�Y���擾����
	std::uintmax_t size() const;
	// �t�@�C�������擾����
	const std::string& get_file_name() const;
};

