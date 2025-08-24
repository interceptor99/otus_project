#pragma once

int Rand( int max_value )
{
	std::srand( std::time( nullptr ) );

	return std::rand() % max_value;
}