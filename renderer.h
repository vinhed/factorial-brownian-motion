#pragma once

#include "include.h"
#include "factorial-brownian-motion.h"

struct Application
{
	SDL_Renderer* gRenderer = nullptr;
	SDL_Window* gWindow = nullptr;
	int windowWidth = 1280;
	int windowHeight = 720;
};

Application* SDLInit();
void drawBrownianMotion(Application* application, FactorialBrownianMotion fBN);