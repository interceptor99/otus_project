#pragma once

#include <fstream>


bool Write( const std::string & high_scores_filename, const std::string & user_name, const int attempts_number )
{
	bool res = true;
	std::ofstream out_file{ high_scores_filename, std::ios_base::app };
	if ( !out_file.is_open() )
	{
		std::cout << "Failed to open file for write: " << high_scores_filename << "!" << std::endl;
		res = false;
	}
	else
	{
		out_file << user_name << ' ';
		out_file << attempts_number;
		out_file << std::endl;
	}

	return res;
}


bool Read( const std::string & high_scores_filename )
{
	bool res = true;
	std::ifstream in_file{ high_scores_filename };
	if ( !in_file.is_open() )
	{
		std::cout << "Failed to open file for read: " << high_scores_filename << "!" << std::endl;
		res = false;
	}
	else
	{
		std::cout << std::endl << "High scores table:" << std::endl;
		std::string username;
		int high_score = 0;
		while ( true )
		{
			in_file >> username;
			in_file >> high_score;
			if ( in_file.fail() ) break;
			std::cout << username << '\t' << high_score << std::endl;
		}
	}

	return res;
}