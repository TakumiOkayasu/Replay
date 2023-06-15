#include <string>
#include <fstream>
#include <iterator>
#include <utility>
#include "../replay/ReplayFileReader.h"
#include "../../lib/Debug.h"

ReplayFileReader::ReplayFileReader( std::string const& repfile ) :
	read_count( 0 ),
	replay_file_name( repfile ),
	replay_data()
{
}

void ReplayFileReader::read()
{
	std::ifstream ifs( replay_file_name, std::ios::binary | std::ios::in );

	while( ifs.peek() != std::ios::traits_type::eof() ) {
		ReplayData_t d {};
		ifs.read( reinterpret_cast< char* >( &d.input ), sizeof( d.input ) );
		ifs.read( reinterpret_cast< char* >( &d.game_count ), sizeof( d.game_count ) );
		replay_data.push_back( d );
	}
}

ReplayData_t ReplayFileReader::get_replay_data() const
{
	const auto now = std::begin( replay_data ) + read_count;

	// �d�l�I�ɁA0�t���[���ڂ����݂��Ȃ��̂ŁA0��������I���Ƃ���
	if( now == std::end( replay_data ) ) {
		return { 0, 0 };
	}

	return *now;
}

void ReplayFileReader::next()
{
	++read_count;
}

// �ŏ�����Đ�����ꍇ
void ReplayFileReader::from_the_beginning()
{
	read_count = 0;
}
