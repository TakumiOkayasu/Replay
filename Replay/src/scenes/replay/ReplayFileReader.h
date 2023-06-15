#pragma once
#include <string>
#include <vector>
#include <memory>
#include "../../lib/Utility.h"
#include "../../lib/FileReader.h"
#include "ReplayData.h"

class ReplayFileReader :
	public FileReader
{
	unsigned read_count;
	std::string replay_file_name;
	std::vector< ReplayData_t > replay_data;

public:

	ReplayFileReader() = default;
	ReplayFileReader( std::string const& repfile );
	~ReplayFileReader() = default;

	void read();
	ReplayData_t get_replay_data() const;
	void next();
	void from_the_beginning();
};

