#include "include.h"
#include "renderer.h"
#include "factorial-brownian-motion.h"


int main(int argc, char* argv[])
{
	Application* application = SDLInit();

	int seed = -1;
	int frequence = application->windowWidth;
	int amount = 1;
	float H = 1;

	FactorialBrownianMotion fBN(seed, frequence, amount, H);

	bool init = true;
	while (true)
	{
		const Uint8* state = SDL_GetKeyboardState(NULL);

		if (state[SDL_SCANCODE_R] || init)
		{
			init = false;
			seed = -1;
			fBN.generate();
			fBN.normalize();
			drawBrownianMotion(application, fBN);
		}

		SDL_PumpEvents();
	}
	

	return 0;
}