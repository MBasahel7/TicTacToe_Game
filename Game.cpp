#include "Game.h"
#include <iostream>


int main()
{
	int x=1;
	char a;
	while (x == 1) {
		Game g;
		g.start();	
		std::cout << std::endl << "Would you like to play again yes or no(y/n)";
		std::cin >> a;
		if (a == 'n')
			x = 0;

	}
	
	
}

