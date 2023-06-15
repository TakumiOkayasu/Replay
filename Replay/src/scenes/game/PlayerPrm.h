#pragma once

#include <string>

struct PlayerPrm_t
{
	int				hit_range;
	int				move_speed;
	std::string		image_file_name;

	PlayerPrm_t() :
		hit_range(),
		move_speed(),
		image_file_name()
	{
	}

	PlayerPrm_t( int range, int spd, std::string const& img ) :
		hit_range( range ),
		move_speed( spd ),
		image_file_name( img )
	{
	}
};

