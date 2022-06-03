#include "renderer.h"

Application* SDLInit()
{
	Application* application = new Application;
	SDL_Init(SDL_INIT_VIDEO);
	application->gWindow = SDL_CreateWindow("Factorial Brownian Motion", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, application->windowWidth, application->windowHeight, SDL_WINDOW_SHOWN);
	application->gRenderer = SDL_CreateRenderer(application->gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	return application;
}

void setColors(Application* application, SDL_Color color, SDL_Point* points, int nrOfPoints)
{
	SDL_SetRenderDrawColor(application->gRenderer, color.r, color.b, color.g, color.a);
	SDL_RenderDrawPoints(application->gRenderer, points, nrOfPoints);
	SDL_SetRenderDrawColor(application->gRenderer, 0x0, 0x0, 0x0, 0xFF);
}

void setColor(Application* application, SDL_Color color, SDL_Point point)
{
	SDL_SetRenderDrawColor(application->gRenderer, color.r, color.b, color.g, color.a);
	SDL_RenderDrawPoint(application->gRenderer, point.x, point.y);
	SDL_SetRenderDrawColor(application->gRenderer, 0x0, 0x0, 0x0, 0xFF);
}

float cosColor(FactorialBrownianMotion fBN, int x, int channel)
{
	float a = fBN.values[x];
	float b = fBN.values[x + MAX_SIZE];
	float c = fBN.values[x + (MAX_SIZE * 2)];
	float d = fBN.values[x + (int)(MAX_SIZE * 1.5f)];
	return a + b * cosf(6.28318530718f * (c * ((float)x / fBN.n) + (d / channel)));
}

SDL_Color getCosColor(FactorialBrownianMotion fBN, int x)
{
	SDL_Color c = { cosColor(fBN, x, 1) * 255, cosColor(fBN, x, 2) * 255, cosColor(fBN, x, 3) * 255, 255};
	return c;
}

SDL_Color getColor(FactorialBrownianMotion fBN, int x, int y)
{
	SDL_Color clr = {
		255 * fBN.values[x] * fBN.values[y + (MAX_SIZE * 3)],
		255 * fBN.values[x + MAX_SIZE] * fBN.values[y + (MAX_SIZE * 4)],
		255 * fBN.values[x + (MAX_SIZE * 2)] * fBN.values[y + (MAX_SIZE * 5)],
		255 
	};
	return clr;
}

void drawBrownianMotion(Application* application, FactorialBrownianMotion fBN)
{
	SDL_RenderClear(application->gRenderer);
	
	for (int x = 0; x < fBN.n; x++)
	{
		for (int y = 0; y < application->windowHeight; y++)
		{
			SDL_Point point = {x, y};
			setColor(application, getColor(fBN, x, y), point);
		}
	}
	
	SDL_RenderPresent(application->gRenderer);
}