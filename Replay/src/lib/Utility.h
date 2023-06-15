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
	*	座標を表す
	*/
	template< typename T >
	struct pos_t
	{
		T x, y;
	};

	/*
	*	四角形を表す
	*	左上の座標と、高さと幅で表現する
	*/
	template< typename T >
	struct square
	{
		pos_t< T >	left_top;
		pos_t< T >	size;
	};

	/*
	*	value が [ minimum, maximum ] になるように clamp する
	*/
	template< typename T >
	static constexpr T clamp( T value, T minimum, T maximum )
	{
		return std::min( std::max( value, minimum ), maximum );
	}

	/*
	*	@brief	[ minimum, minimum ) の範囲でラップアラウンドする
	*	@param	value		現在の値
	*			minimum		最小値
	*			maximum		最大値
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
	*	文字列を delimiter ごとに区切って std::vector に入れて返す
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
	*	std::shared_ptr のオブジェクトを返す
	*/
	template< typename T >
	static auto make_object( T&& )
	{
		return std::make_shared< T >();
	}
	
	/*
	*	ファイルがあるか調べる
	*/
	static bool is_exists( std::string const& f )
	{
		return fs::exists( f );
	}

	/*
	*	ファイルを新規作成し、即座にファイルを閉じる
	*/
	static void make_new_file( std::string const& file_name )
	{
		std::ofstream ofs( file_name );
	}
};
