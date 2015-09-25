#pragma once
#include "Error.h"
#include <iostream>
#include <SDL/SDL.h>

namespace Engine{
void dispError(std::string messageStr)
{
	std::cout << messageStr << std::endl;
	SDL_Quit();

	system("pause");
	exit(1);
}
}