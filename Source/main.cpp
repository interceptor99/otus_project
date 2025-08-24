#include "argument.h"
#include "check_value.h"
#include "high_scores.h"
#include "random_value.h"


int main( int argc, char ** argv ) 
{
	const int max_value = Max( argc, argv );
	const int target_value = Rand( max_value );

	std::cout << "Hi! Enter your name, please:" << std::endl;
	std::string user_name;
	std::cin >> user_name;

	const int attempts_number = Check( target_value );
	const std::string high_scores_filename = "high_scores.txt";
	if ( Write( high_scores_filename, user_name, attempts_number ) )
	{
		if ( Read( high_scores_filename ) )
			return 0;
		else
			return -1;
	}
	else
		return -1;
}