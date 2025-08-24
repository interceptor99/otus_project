#pragma once

#include <iostream>

int Check( int target_value )
{
	int current_value = 0;
	bool not_win = true;
	int attempts_number = 0;

	std::cout << "Enter your guess:" << std::endl;

	do {
		std::cin >> current_value;

		++attempts_number;

		if ( current_value < target_value )
			std::cout << "greater than " << current_value << std::endl;
		else if ( current_value > target_value )
			std::cout << "less than " << current_value << std::endl;
		else
		{
			std::cout << "you win! attempts = " << attempts_number << std::endl;
			break;
		}
	} while ( true );

	return attempts_number;
}