#pragma once

#include <string>

int Max( int argc, char ** argv )
{
	int max_value = 100;
	if ( argc >= 2 )
	{
		std::string arg1_value{ argv[1] };
		if ( arg1_value == "-max" )
		{
			int par_value{ atoi( argv[2] ) };
			if ( par_value > 0 )
				max_value = par_value;
		}
	}

	return max_value;
}