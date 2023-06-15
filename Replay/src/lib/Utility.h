#pragma once

#include <memory>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <filesystem>

#if 1
	namespace fs = std::experimental::filesystem;
#else
	using fs = std::filesystem;
#endif


#undef max
#undef min

class Utility
{
public:

	/*
	*	���W��\��
	*/
	template< typename T >
	struct pos_t
	{
		T x, y;
	};

	/*
	*	�l�p�`��\��
	*	����̍��W�ƁA�����ƕ��ŕ\������
	*/
	template< typename T >
	struct square
	{
		pos_t< T >	left_top;
		pos_t< T >	size;
	};

	/*
	*	value �� [ minimum, maximum ] �ɂȂ�悤�� clamp ����
	*/
	template< typename T >
	static constexpr T clamp( T value, T minimum, T maximum )
	{
		return std::min( std::max( value, minimum ), maximum );
	}

	/*
	*	@brief	[ minimum, minimum ) �͈̔͂Ń��b�v�A���E���h����
	*	@param	value		���݂̒l
	*			minimum		�ŏ��l
	*			maximum		�ő�l
	*/
	template< typename T >
	static constexpr T wrap_around( T value, T minimum, T maximum )
	{
		if( minimum > maximum ) {
			std::swap( maximum, minimum );
		}

		const T n = ( value - minimum ) % ( maximum - minimum );
		return n >= 0 ? ( n + minimum ) : ( n + maximum );
	}

	/*
	*	������� delimiter ���Ƃɋ�؂��� std::vector �ɓ���ĕԂ�
	*/
	static std::vector< std::string > split( const std::string& input, char delimiter = ' ' )
	{
		std::istringstream stream( input );
		std::string field {};
		std::vector< std::string > result {};

		while( std::getline( stream, field, delimiter ) ) {
			result.push_back( field );
		}

		return result;
	}

	/*
	*	std::shared_ptr �̃I�u�W�F�N�g��Ԃ�
	*/
	template< typename T >
	static auto make_object( T&& )
	{
		return std::make_shared< T >();
	}
	
	/*
	*	�t�@�C�������邩���ׂ�
	*/
	static bool is_exists( std::string const& f )
	{
		return fs::exists( f );
	}

	/*
	*	�t�@�C����V�K�쐬���A�����Ƀt�@�C�������
	*/
	static void make_new_file( std::string const& file_name )
	{
		std::ofstream ofs( file_name );
	}
};
